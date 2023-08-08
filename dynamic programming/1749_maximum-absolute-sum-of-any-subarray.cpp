class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveMax = 0, negativeMin = 0;
        int positiveSum = 0, negativeSum = 0;
        for (int num : nums) {
            positiveSum += num;
            positiveMax = max(positiveMax, positiveSum);
            positiveSum = max(0, positiveSum);
            negativeSum += num;
            negativeMin = min(negativeMin, negativeSum);
            negativeSum = min(0, negativeSum);
        }
        return max(positiveMax, -negativeMin);
    }
};



class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int preMax = INT_MIN;
        int preMin = INT_MAX;
        int minVal, maxVal;

        minVal = maxVal = nums[0];
        for (int val : nums) {
            /* Get positive max value */
            preMax = max(preMax, 0) + val;
            maxVal = max(preMax, maxVal);
            /* Get negtive max value */
            preMin = min(preMin, 0) + val;
            minVal = min(preMin, minVal);
        }
        
        return max(abs(maxVal), abs(minVal));
    }
};



class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        /* Get positive max value */
        int pre = INT_MIN;
        int maxVal = nums[0];
        for (int val : nums) {
            pre = max(pre, 0) + val;
            maxVal = max(pre, maxVal);
        }
        /* Get negtive max value */
        pre = INT_MAX;
        int minVal = nums[0];
        for (int val : nums) {
            pre = min(pre, 0) + val;
            minVal = min(pre, minVal);
        }
        
        return max(abs(maxVal), abs(minVal));
    }
};



class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        /* Get positive max value */
        int preMax = INT_MIN;
        int maxVal = nums[0];
        for (int val : nums) {
            preMax = max(preMax, 0) + val;
            maxVal = max(preMax, maxVal);
        }
        /* Get negtive max value */
        int preMin = INT_MAX;
        int minVal = nums[0];
        for (int val : nums) {
            preMin = min(preMin, 0) + val;
            minVal = min(preMin, minVal);
        }
        
        return max(abs(maxVal), abs(minVal));
    }
};


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxVal = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        
       int minVal = nums[0];
       for (int i = 1; i < n; i++) {
           dp[i] = 0;
       }
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[i - 1] + nums[i], nums[i]);
            minVal = min(minVal, dp[i]);
        }       
        return max(abs(maxVal), abs(minVal));
    }
};

