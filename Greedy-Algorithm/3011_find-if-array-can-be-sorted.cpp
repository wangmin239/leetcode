class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastCnt = 0;
        int lastGroupMax = 0;
        int curGroupMax = 0;
        
        int* nums = nums.data();
        int numsSize = nums.size();

        for (int i = 0; i < numsSize; i++) {
            int num = nums[i];
            int curCnt = __builtin_popcount(num);
            if (curCnt == lastCnt) {
                curGroupMax = fmax(curGroupMax, num);
            } else {
                lastCnt = curCnt;
                lastGroupMax = curGroupMax;
                curGroupMax = num;
            }
            if (num < lastGroupMax) {
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int preMax = INT_MIN;

        for (size_t i = 0; i < nums.size(); ) {
            int oneBits = __builtin_popcount(nums[i]);
            int curMin = nums[i];
            int curMax = nums[i];

            while (++i < nums.size() && oneBits == __builtin_popcount(nums[i])) {
                curMin = min(curMin, nums[i]);
                curMax = max(curMax, nums[i]);
            }

            if (curMin < preMax) {
                return false;
            }
            preMax = curMax;           
        }

        return true;
    }
};