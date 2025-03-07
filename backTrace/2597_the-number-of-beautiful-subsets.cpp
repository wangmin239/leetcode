/* Official Solution 1 */
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) {
                ans++;
                return;
            }
            dfs(i + 1);
            if (cnt[nums[i] - k] == 0 && cnt[nums[i] + k] == 0) {
                ++cnt[nums[i]];
                dfs(i + 1);
                --cnt[nums[i]];
            }
        };
        dfs(0);
        return ans - 1;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, map<int, int>> groups;
        for (int a : nums) {
            ++groups[a % k][a];
        }
        int ans = 1;
        for (auto& [_, g] : groups) {
            int m = g.size();
            vector<vector<int>> f(m, vector<int>(2, 0));
            f[0][0] = 1, f[0][1] = (1 << g.begin()->second) - 1;
            int i = 1;
            for (auto it = next(g.begin()); it != g.end(); it++, i++) {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                if (it->first - prev(it)->first == k) {
                    f[i][1] = f[i - 1][0] * ((1 << it->second) - 1);
                } else {
                    f[i][1] =
                        (f[i - 1][0] + f[i - 1][1]) * ((1 << it->second) - 1);
                }
            }
            ans *= f[m - 1][0] + f[m - 1][1];
        }
        return ans - 1;
    }
};
