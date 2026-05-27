/* Original Solution 1 */
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i;

        for (i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }

        
        if (i < n - 1 && nums.front() < nums.back()) {
            return false;
        }


        for (int j = n - 1; j > i + 1; j--) {
            if (nums[j] < nums[j - 1]) {
                return false;
            }
        }

        return true;
    }
};



/* Official Solution 1 */
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), x = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                x = i;
                break;
            }
        }
        if (x == 0) {
            return true;
        }
        for (int i = x + 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return nums[0] >= nums[n - 1];
    }
};
