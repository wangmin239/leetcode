class Solution {
public:
    bool isSatisfied(vector<int> &nums, int l, int r, int threshold) {
        if (nums[l] % 2 != 0) {
            return false;
        }
        for (int i = l; i <= r; i++) {
            if (nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2)) {
                return false;
            }
        }
        return true;
    }

    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, n = nums.size();
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (isSatisfied(nums, l, r, threshold)) {
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, dp = 0, n = nums.size();
        for (int l = n - 1; l >= 0; l--) {
            if (nums[l] > threshold) {
                dp = 0;
            } else if (l == n - 1 || nums[l] % 2 != nums[l + 1] % 2) {
                dp++;
            } else {
                dp = 1;
            }
            if (nums[l] % 2 == 0) {
                res = max(res, dp);
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;
        int size = nums.size();

        for (int left = 0, right = 0; right < size; right++){
            bool isBig = false;
            while (right < size) {
                if (nums[right] > threshold) {
                    isBig = true;
                    break;
                }
                if (((right - left) & 0x1) ^ (nums[right] & 0x1)){
                    break;
                }
                ++right;
            }
            maxLen = max(maxLen, right - left);
            left = right;
            if (isBig == true || (right < size && (nums[right] & 1))) {
                ++left;
            }
        }
        return maxLen;
    }
};