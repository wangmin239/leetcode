class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};




class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
           for (int num : nums) {
                if (num > i) {
                    continue;
                }
                dp[i] += dp[i - num];
           }
        }
        
        return dp[target];
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        
        dfs(nums, target, ans);
        return ans;
    }
    
    void dfs(const vector<int>& nums, int target, int& ans) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            ++ans;
            return;
        }
        
        for (const int value : nums) {
            if (value > target) {
                continue;
            }
            dfs(nums, target - value, ans);
        }
        
    }
};