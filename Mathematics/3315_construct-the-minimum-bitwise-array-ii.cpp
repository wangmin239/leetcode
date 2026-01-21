/* Original Solution 1 */
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                continue;
            }

            int tailOnes = countr_one(static_cast<unsigned int>(nums[i]));
            int totalOnes = popcount(static_cast<unsigned int>(nums[i]));

            if (totalOnes == tailOnes) {
                ans[i] = nums[i] >> 1;
            } else {
                ans[i] = nums[i] ^ (1 << (tailOnes - 1));
            }
        }
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) { // 注意这里是引用
            if (x == 2) {
                x = -1;
            } else {
                x ^= ((x + 1) & ~x) >> 1;
            }
        }
        return nums;
    }
};
