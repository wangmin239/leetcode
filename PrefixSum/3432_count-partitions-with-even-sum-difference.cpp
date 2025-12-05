/* Original Solution 1 */
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = reduce(nums.begin(), nums.end(), 0);
        int cnt = 0;
        int presum = 0;

        for (size_t i = 0;  i < nums.size() - 1; i++) {
            presum += nums[i];
            if ((sum - presum * 2) % 2 == 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s = reduce(nums.begin(), nums.end());
        return s % 2 ? 0 : nums.size() - 1;
    }
};
