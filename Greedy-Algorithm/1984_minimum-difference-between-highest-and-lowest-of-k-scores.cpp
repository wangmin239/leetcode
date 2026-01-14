class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        
        int size = nums.size();
        int minDiff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= size - k; i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }

        return minDiff;
    }
};