/* Original Solution 1 */
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp.front() = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp.back() > 0 ? dp.back() : -1;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(n, INT_MIN);
        
        function<int(int)> dfs = [&](int i) -> int {
            if (i == n - 1) {
                return 0;
            }
            if (memo[i] != INT_MIN) {
                return memo[i];
            }
            int res = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    res = max(res, dfs(j) + 1);
                }
            }
            return memo[i] = res;
        };
        
        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] < 0 ? -1 : dp[n - 1];
    }
};


/* Official Solution 3 */
class SegmentTree {
    vector<int> tree;

public:
    SegmentTree(int n) : tree(2 << bit_width(n - 1u), INT_MIN) {}

    void update(int node, int l, int r, int i, int val) {
        if (l == r) { // 叶子
            tree[node] = val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) { // i 在左子树
            update(node * 2, l, m, i, val);
        } else { // i 在右子树
            update(node * 2 + 1, m + 1, r, i, val);
        }
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) { // 当前子树完全在 [ql, qr] 内
            return tree[node];
        }
        int m = (l + r) / 2;
        if (qr <= m) { // [ql, qr] 在左子树
            return query(node * 2, l, m, ql, qr);
        }
        if (ql > m) { // [ql, qr] 在右子树
            return query(node * 2 + 1, m + 1, r, ql, qr);
        }
        return max(query(node * 2, l, m, ql, qr), query(node * 2 + 1, m + 1, r, ql, qr));
    }
};

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // 排序去重，便于离散化
        auto sorted = nums;
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());

        int n = nums.size();
        int m = sorted.size();

        SegmentTree t(m); // 值域线段树

        // nums[0] 对应的 f[0] = 0
        int pos = ranges::lower_bound(sorted, nums[0]) - sorted.begin();
        t.update(1, 0, m - 1, pos, 0);

        long long tar = target;
        for (int j = 1; ; j++) {
            int l = ranges::lower_bound(sorted, nums[j] - tar) - sorted.begin();     // >= nums[j]-target 的第一个数
            int r = ranges::upper_bound(sorted, nums[j] + tar) - sorted.begin() - 1; // <= nums[j]+target 的最后一个数
            // t.query 返回满足 nums[j]-target <= nums[i] <= nums[j]+target 的最大的 f[i]
            int fj = t.query(1, 0, m - 1, l, r) + 1;
            if (j == n - 1) {
                return fj < 0 ? -1 : fj;
            }
            pos = ranges::lower_bound(sorted, nums[j]) - sorted.begin();
            t.update(1, 0, m - 1, pos, fj);
        }
    }
};
