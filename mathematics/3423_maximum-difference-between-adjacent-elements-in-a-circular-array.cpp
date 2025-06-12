/* Original Solution 1 */
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;
        
        for (int i = 1; i <= n; i++) {
            maxDiff = max(maxDiff, abs(nums[i % n] - nums[(i - 1) % n]));
        }
        
        return maxDiff;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
};

