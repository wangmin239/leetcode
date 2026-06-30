/* Original Solution 1 */
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for (int right = 0; right < n; right++) {
            int curCnt = 0;
            for (int left = right; left >= 0; left--) {
                if (nums[left] == target) {
                    ++curCnt;
                }

                if (curCnt > (right - left + 1) / 2) {
                    ++total;
                }
            }

        }
        return total;
    }
};