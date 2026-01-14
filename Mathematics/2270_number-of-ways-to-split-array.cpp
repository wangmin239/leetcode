class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long left = 0, right = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) {
                ++ans;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ans = accumulate(nums.begin(), nums.end(), 0LL);
        long long preSum = 0;
        int cnt = 0;
        
        for (size_t i = 0; i < nums.size() - 1; i++) {
            preSum += nums[i];
            if (preSum >= ans - preSum) {
                cnt++;
            }
        }
        
        return cnt;
        
    }
};