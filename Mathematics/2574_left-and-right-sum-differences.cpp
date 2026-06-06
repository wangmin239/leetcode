/* Original Solution 1 */
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + nums[i - 1];
        }

        for (int i = n - 1, sum = 0; i >= 0; i--) {
            ans[i] = abs(ans[i] - sum);
            sum += nums[i];
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = reduce(nums.begin(), nums.end());

        int left_sum = 0;
        for (int& x : nums) {
            left_sum += x; // 这样写的话，left_sum 包含 x
            x = abs(left_sum * 2 - x - total);
        }
        return nums;
    }
};
