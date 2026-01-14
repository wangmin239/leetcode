class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            if (i >= 2) {
                dp[i] = dp[i - 2] && validTwo(nums[i - 2], nums[i - 1]);
            }
            if (i >= 3) {
                dp[i] = dp[i] || (dp[i - 3] && validThree(nums[i - 3], nums[i - 2], nums[i - 1]));
            }
        }  
        return dp[n];
    }

    bool validTwo(int num1, int num2) {
        return num1 == num2;
    }

    bool validThree(int num1, int num2, int num3) {
        return (num1 == num2 && num1 == num3) || (num1 + 1 == num2 && num2 + 1 == num3);
    }
};        




class Solution {
public:
    bool validPartition(vector<int>& nums) {
        return dfs(0, nums);
    }
    
    bool dfs(int start, vector<int>& nums) {
        int remain = nums.size() - start;
        if (remain == 0) {
            return true;
        }
        
        if (remain == 1) {
            return false;
        }
        
        bool twoEles = (nums[start] == nums[start + 1]);
        if (remain == 2) {
            return twoEles;
        }
        
        bool threeEles = true;
        for (int i = 1; i < 3; i++) {
            if ((nums[start] != nums[start + i]) && (nums[start + i] - nums[start] != i)) {
                threeEles = false;
                break;
            }
        }
        if (remain == 3) {
            return threeEles;
        }
        
        return (dfs(start + 2, nums) && twoEles) || (dfs(start + 3, nums)&& threeEles); 
    }
};

