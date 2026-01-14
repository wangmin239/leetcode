
/* Official Solution 1 */
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = ranges::max(nums);
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == mx) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0; // 连续 mx 断开了，重新统计
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = nums[0];
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                ans = cnt = 1;
                maxValue = nums[i];
            } else if (nums[i] < maxValue) {
                cnt = 0;
            } else if (nums[i] == maxValue) {
                cnt++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};
