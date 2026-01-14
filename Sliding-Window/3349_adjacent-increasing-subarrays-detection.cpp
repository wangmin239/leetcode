/* Original Solution 1 */
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        
        for (int i = 0; i <= n - 2 * k; i++) {
            int j = i + k;
            int step = 0;
            /* Check that the partition is strictly ascending. */
            while (step < k - 1){
                if (nums[i + step] < nums[i + step + 1] && nums[j + step] < nums[j + step + 1]) {
                    step++;
                } else {
                    break;
                }
            }
            
            if (step == k - 1) {
                return true;
            }
        }
        
        return false;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            }
            else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
};
