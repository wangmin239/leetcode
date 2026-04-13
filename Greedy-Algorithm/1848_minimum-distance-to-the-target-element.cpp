/* Original Solution 1 */
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = n;

        for (int left = start; left >= 0; left--) {
            if (nums[left] == target) {
                ans = start - left;
                break;
            }
        }

        for (int right = start + 1; right < n; right++) {
            if (nums[right] == target) {
                ans = min(ans, right - start);
                break;
            }
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int k = 0; ; k++) {
            if (start >= k && nums[start - k] == target ||
                start + k < nums.size() && nums[start + k] == target) {
                return k;
            }
        }
    }
};


/* Official Solution 2 */
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == target){
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};
