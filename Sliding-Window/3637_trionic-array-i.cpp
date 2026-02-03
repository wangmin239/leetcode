/* Original Solution 1 */
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i;

        for (i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                break;
            }
        }

        if (i == 1 || i == n || nums[i] == nums[i - 1]) {
            return false;
        }

        while (++i < n) {
            if (nums[i - 1] <= nums[i]) {
                break;
            }
        }

        if (i == n || nums[i - 1] == nums[i]) {
            return false;
        }

        while (++i < n) {
            if (nums[i - 1] >= nums[i]) {
                break;
            }
        }

        return i == n;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0] >= nums[1]) { // 一开始必须是递增的
            return false;
        }
        int cnt = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((nums[i - 2] < nums[i - 1]) != (nums[i - 1] < nums[i])) {
                cnt++;
            }
        }
        return cnt == 3; // 一定是增减增
    }
};
