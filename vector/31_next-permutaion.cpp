class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i, j;
        for (i = size - 2; i >= 0 && nums[i] >= nums[i + 1]; ) {
            i--;
        }

        if (i >= 0) {
            j = size - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};