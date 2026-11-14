/* Original Solution 1 */
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        for (int left = 0; left < n; left++) {
            for (int right = left + l - 1; right < min(left + r, n); right++) {
                int diff = preSum[right + 1] - preSum[left];

                if (diff > 0) {
                    ans = min(ans, diff);
                }
            }
        }

        return ans == INT_MAX ? -1: ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const int n = nums.size();
        vector<int> prefixSum(n + 1);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int minSum = INT_MAX;
        for (int length = l; length <= r; ++length) {
            for (int start = 0; start + length <= n; ++start) {
                const int sum = prefixSum[start + length] - prefixSum[start];
                if (sum > 0 && sum < minSum) {
                    minSum = sum;
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const int n = nums.size();
        int minSum = INT_MAX;

        int initial = 0;
        for (int i = 0; i < l - 1; ++i) {
            initial += nums[i];
        }

        for (int length = l; length <= r; ++length) {
            initial += nums[length - 1];
            int sum = initial;

            if (sum > 0 && sum < minSum) {
                minSum = sum;
            }

            for (int hi = length; hi < n; ++hi) {
                sum += nums[hi] - nums[hi - length];
                if (sum > 0 && sum < minSum) {
                    minSum = sum;
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};
