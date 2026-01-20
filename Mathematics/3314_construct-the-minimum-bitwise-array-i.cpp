/* Original Solution 1 */
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            if ((nums[i] & (nums[i] - 1)) == 0) {
                continue;
            }

            for (int val = nums[i] / 2; val <= nums; val++) {
                if ((val | (val + 1)) == nums[i]) {
                    ans[i] = val;
                    break;
                }
            }
        }

        return ans;
    }
};

/* Original Solution 2 */
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            if ((nums[i] & (nums[i] - 1)) == 0) {
                continue;
            }

            int tailOnes = countr_one(static_cast<unsigned int>(nums[i]));
            int totalOnes = popcount(static_cast<unsigned int>(nums[i]));
            
            if (totalOnes == tailOnes) {
                ans[i] = nums[i] / 2;
            } else {
                ans[i] = nums[i] ^ (1 << (tailOnes - 1));
            }
        }

        return ans;
    }
};