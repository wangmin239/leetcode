/* Original Solution 1 */
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        unordered_map<int, int> freq;

        for (int left = 0, right = 0; right < n; right++) {
            int curNum = nums[right];

            int cnt = ++freq[curNum];

            if (cnt <= k) {
                maxLen = max(maxLen, right - left + 1);
                continue;
            }

            /* Search the number that the count of a number is over k */
            while (nums[left] != curNum) {
                --freq[nums[left++]];
            }

            --freq[curNum];
            ++left;
        }

        return maxLen;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> occ;
        int right = -1, ans = 0;
        for (int left = 0; left < n; ++left) {
            if (left > 0) {
                --occ[nums[left - 1]];
            }
            while (right + 1 < n && occ[nums[right + 1]] < k) {
                ++right;
                ++occ[nums[right]];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, left = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < nums.size(); right++) {
            cnt[nums[right]]++;
            while (cnt[nums[right]] > k) {
                cnt[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
