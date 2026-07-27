/* Original Solution 1 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = 0;
        int secondMaxVal = 0;

        for (int val : nums) {
            if (val >= maxVal) {
                secondMaxVal = maxVal;
                maxVal = val;
            } else if (val > secondMaxVal) {
                secondMaxVal = val;
            }
        }

        return (maxVal - 1) * (secondMaxVal - 1);
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = nums[0], b = nums[1];
        if (a < b) {
            swap(a, b);
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
            } else if (nums[i] > b) {
                b = nums[i];
            }
        }
        return (a - 1) * (b - 1);
    }
};
