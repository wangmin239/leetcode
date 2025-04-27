/* Original Solution */
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        
        for (int i = 2; i < n; i++) {
            if (2 * (nums[i - 2] + nums[i]) == nums[i - 1]) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};

/* Official Solution */
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                ++ans;
            }
        }
        return ans;
    }
};

