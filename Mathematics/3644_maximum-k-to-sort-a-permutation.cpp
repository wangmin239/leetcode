/* Original Solution 1 */
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxVal = (1 << bit_width(n)) - 1;
        int k = maxVal;


        for (int i = 0; i < n; i++) {
            if (i != nums[i]) {
                k &= nums[i];
            }
        }


        if (k == maxVal) {
            return 0;
        }


        return k;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            res &= nums[i];
        }
        return res == INT_MAX ? 0 : res;
    }
};
