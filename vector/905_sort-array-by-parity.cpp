class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        vector<int> ans(len);
        
        for (const auto& val : nums) {
            if (val & 0x1) {
                ans[right--] = val;
            } else {
                ans[left++] = val;
            }
        }
        return ans;
        
    }
};




class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        
        while (left < right) {
            if ((nums[left] & 0x1) == 0) {
                left++;
                continue;
            }
            
            if ((nums[right] & 0x1) == 1) {
                right--;
                continue;
            }
            
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return nums;
        
    }
};