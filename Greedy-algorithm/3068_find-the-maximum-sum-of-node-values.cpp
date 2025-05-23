/* Official Solution 1 */
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long res = accumulate(nums.begin(), nums.end(), 0ll);
        vector<int> diff;
        for (auto& a : nums) {
            diff.push_back((a ^ k) - a);
        }
        sort(diff.begin(), diff.end());
        for (int i = diff.size() - 1; i > 0 && diff[i] + diff[i - 1] >= 0;
             i -= 2) {
            res += max(0, diff[i] + diff[i - 1]);
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        function<pair<long long, long long>(int, int)> dfs = [&](int u, int fa) -> pair<long long, long long> {
            long long f0 = 0, f1 = LLONG_MIN;
            for (auto &v : g[u]) {
                if (v != fa) {
                    auto [r0, r1] = dfs(v, u);
                    long long t = max(f1 + r0, f0 + r1);
                    f0 = max(f0 + r0, f1 + r1);
                    f1 = t;
                }
            }
            return {max(f0 + nums[u], f1 + (nums[u] ^ k)), max(f1 + nums[u], f0 + (nums[u] ^ k))};
        };
        return dfs(0, -1).first;
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
        long long f0 = 0, f1 = LLONG_MIN;
        for (int x : nums) {
            long long t = max(f1 + x, f0 + (x ^ k));
            f0 = max(f0 + x, f1 + (x ^ k));
            f1 = t;
        }
        return f0;
    }
};