class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};





class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        int minDiff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, abs(nums[i] - nums[i - 1]));
        }
        
        return minDiff;
    }
};