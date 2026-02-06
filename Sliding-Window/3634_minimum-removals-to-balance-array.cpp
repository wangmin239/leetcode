/* Original Solution 1 */
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int maxRange = 0;
        int left, right;

        sort(nums.begin(), nums.end());

        for (left = 0, right = 0; right < n; right++) {
            if ((nums[right] + k - 1) / k > nums[left]) {
                maxRange = max(maxRange, right - left);
                ++left;
            }
        }

        maxRange = max(maxRange, right - left);
        return n - maxRange;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ranges::sort(nums);
        int max_save = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (1LL * nums[left] * k < nums[i]) {
                left++;
            }
            max_save = max(max_save, i - left + 1);
        }
        return nums.size() - max_save;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n, right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && nums[right] <= static_cast<long long>(nums[left]) * k) {
                ++right;
            }
            ans = min(ans, n - (right - left));
        }

        return ans;
    }
};