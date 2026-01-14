class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int len = nums.size();
        int minVal = nums.back();

        for (int i = len - 3; i >= 0; i--) {
            if (nums[i] > minVal) {
                return false;
            }
            minVal = min(minVal, nums[i + 1]);
        }
        return true;
    }
};