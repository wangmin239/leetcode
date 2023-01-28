class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd1 = 0, even1 = 0;
        int odd2 = 0, even2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                odd2 += nums[i];
            } else {
                even2 += nums[i];
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                odd2 -= nums[i];
            } else {
                even2 -= nums[i];
            }
            if (odd1 + even2 == odd2 + even1) {
                ++res;
            }
            if (i & 1) {
                odd1 += nums[i];
            } else {
                even1 += nums[i];
            }
        }
        return res;
    }
};




class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0;
        
        for (int index = 0; index < nums.size(); index++) {
            if (dfs(nums, index) == true) {
                ++ans;
            }
        }
        
        return ans;

    }
    
    bool dfs(vector<int>& nums, int index) {
        int evenSum = 0;
        int oddSum = 0;
        
        for (int i = 0; i < index; i++) {
            if ((i & 0x1) == 1) {
                oddSum += nums[i];
            } else {
                evenSum += nums[i];
            }
        }
        
        
        for (int i = index + 1; i < nums.size(); i++) {
            if ((i & 0x1) == 1) {
                evenSum += nums[i];
            } else {
                oddSum += nums[i];
            }
        }
        
        
        return evenSum == oddSum;
        
    }
};