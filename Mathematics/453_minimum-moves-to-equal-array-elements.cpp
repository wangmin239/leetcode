/* Original Solution 1 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int minVal = *min_element(nums.begin(), nums.end());

        for (int val : nums) {
            ans += val - minVal;
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        return reduce(nums.begin(), nums.end(), 0LL) - 1LL * ranges::min(nums) * nums.size();
    }
};
