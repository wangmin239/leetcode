class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isIncreasing(nums, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }

    bool isIncreasing(vector<int>& nums, int l, int r) {
        for (int i = 1; i < nums.size(); i++) {
            if (i >= l && i <= r + 1) {
                continue;
            } 
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        if (l - 1 >= 0 && r + 1 < nums.size() && nums[r + 1] <= nums[l - 1]) {
            return false;
        }
        return true;
    }
};

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int l = 1;
        while (l < n && nums[l - 1] < nums[l]) {
            l++;
        }
        res += l + (l < n);
        for (int r = n - 2; r >= 0; r--) {
            while (l > 0 && nums[l - 1] >= nums[r + 1]) {
                l--;
            }
            res += l + (l <= r);
            if (nums[r] >= nums[r + 1]) {
                break;
            }
        }
        return res;
    }
};
