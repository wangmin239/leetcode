class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        
        for (size_t i = 0; i < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        
        return nums;
    }
};


class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        vector<int> ans(nums);
        for (size_t i = 0; i < nums.size(); i += 2) {
            ans[i] = nums[i + 1];
            ans[i + 1] = nums[i];
        }
        
        return ans;
    }
};