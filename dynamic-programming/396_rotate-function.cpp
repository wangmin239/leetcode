class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};








class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int curSum = 0;
        int size = nums.size();
        
        if (size < 2) {
            return 0;
        }
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            curSum += i * nums[i];
        }
        
        int maxSum = curSum;
        for (int i = 1; i < size; i++) {
            int nextSum = curSum + sum - size * nums[size - i];
            curSum = nextSum;
            maxSum = max(maxSum, nextSum);
        }
        return maxSum;
    }
};

