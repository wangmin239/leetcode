class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0;
        for (int i = 0; i < len; i++) {
            if (preSum == sum - nums[i]) {
                return i;
            }
            preSum += nums[i];
            sum -= nums[i];
        }
        
        return -1;
    }
};



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        vector<int> preSum(len + 1, 0);
        
        for (int i = 0; i < len; i++) {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        
        
        for (int i = 0; i < len; i++) {
            if (preSum[i] == preSum[len] - preSum[i + 1]) {
                return i;
            }   
        }
        
        return -1;
    }
};

