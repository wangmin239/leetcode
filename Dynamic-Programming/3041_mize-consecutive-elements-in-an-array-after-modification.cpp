/* Official Solution 1 */
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;
        for (int x : nums) {
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        int f0 = 0, f1 = 0, f2 = 0;
        int pre = 0; // pre 初始值随意，不影响计算
        int ans = 0;
        for (int x : nums) {
            if (x == pre + 1) {
                // 类似 70. 爬楼梯 的空间优化
                f0 = f1;
                f1 = f2;
            } else if (x == pre + 2) {
                f0 = f2;
                f1 = 0;
            } else if (x > pre + 2) {
                f0 = 0;
                f1 = 0;
            }

            f2 = f1 + 1;
            f1 = f0 + 1;
            ans = max(ans, max(f1, f2));
            pre = x;
        }
        return ans;
    }
};
