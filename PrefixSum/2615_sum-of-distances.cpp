/* Origin Solution 1 */
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> numIds;
        int n = nums.size();
        vector<long long> ans(n, 0LL);
        const int lowLimit = 2;

        for (int i = 0; i < n; i++) {
            numIds[nums[i]].push_back(i);
        }

        for (const auto& [_, ids] : numIds) {
            int cnt = ids.size();

            if (cnt < lowLimit) {
                continue;
            }
            int id = ids.front();
            ans[id] = accumulate(ids.begin(), ids.end(), 0LL) - 1LL * id * cnt ;
            for (int j = 1; j < cnt; j++) {
                ans[ids[j]] = ans[ids[j - 1]] - 1LL * (ids[j] - ids[j - 1]) * (cnt - 2 * j);
            }
        }

        return ans;
    }
};


/* Official  Solution 1 */
class Solution {
public:
    vector<long long> distance(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i)
            groups[nums[i]].push_back(i); // 相同元素分到同一组，记录下标

        vector<long long> ans(n);
        long long s[n + 1];
        s[0] = 0;
        for (auto &[_, a]: groups) {
            int m = a.size();
            for (int i = 0; i < m; ++i)
                s[i + 1] = s[i] + a[i]; // 前缀和
            for (int i = 0; i < m; ++i) {
                long long target = a[i];
                long long left = target * i - s[i]; // 蓝色面积
                long long right = s[m] - s[i] - target * (m - i); // 绿色面积
                ans[target] = left + right;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i)
            groups[nums[i]].push_back(i); // 相同元素分到同一组，记录下标

        vector<long long> ans(n);
        for (auto& [_, a]: groups) {
            int m = a.size();
            long long s = 0;
            for (int x: a)
                s += x - a[0]; // a[0] 到其它下标的距离之和
            ans[a[0]] = s;
            for (int i = 1; i < m; ++i)
                // 从计算 a[i-1] 到计算 a[i]，考虑 s 增加了多少
                ans[a[i]] = s += (long long) (i * 2 - m) * (a[i] - a[i - 1]);
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        vector<long long> res(n);
        for (const auto& p : groups) {
            const auto& group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;
            for (int i = 0; i < group.size(); i++) {
                res[group[i]] = total - prefixTotal * 2 + group[i] * (2 * i - group.size());
                prefixTotal += group[i];
            }
        }
        return res;
    }
};
