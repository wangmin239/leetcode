/* Official Solution 1 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> numFreq;

        ranges::sort(nums);
        for (const int num : nums) {
            ans = max(ans, ++numFreq[num]);
        }
        
        for (int i = 0, left = 0, left2 = 0, right = 0; i < n;) {
            int curVal = nums[i];
            /* case 1: Replace all consecutive elements within a range with
             * a value that does not exist in the range
             */
            while (nums[left2] < curVal - k * 2) {
                left2 += numFreq[nums[left2]];
            }
            i += numFreq[nums[i]];
            ans = max(ans, min(i - left2, numOperations));


            /* case 2: Replace all consecutive elements in a range with a
             * specified value nums[i]
             */

            while (nums[left] < curVal - k) {
                left += numFreq[nums[left]];
            }
            while (right < n && nums[right] <= curVal + k) {
                right += numFreq[nums[right]];
            }
            
            ans = max(ans, min(right - left, numFreq[curVal] + numOperations));
        }

        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int ans = 0;

        ranges::sort(nums);
        
        for (int i = 0, left = 0, leftmost = 0, right = 0; i < n; ) {
            int curVal = nums[i++];
            int curCnt = 1;
            /* case 1: Replace all consecutive elements within a range with
             * a value that does not exist in the range
             */
            while (nums[leftmost] < curVal - 2 * k) {
                ++leftmost;
            }
            
            while (i < n && nums[i] == nums[i - 1]) {
                ++curCnt;
                ++i;
            }
            
            ans = max(ans, min(i - leftmost, numOperations));


            /* case 2: Replace all consecutive elements in a range with a
             * specified value nums[i]
             */

            while (nums[left] < curVal - k) {
                ++left;
            }
            while (right < n && nums[right] <= curVal + k) {
                ++right;
            }
            
            ans = max(ans, min(right - left, curCnt + numOperations));
        }

        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0;
        map<int, int> freq;
        unordered_map<int, int> cnt;
        
        for (const int num : nums) {
            ++cnt[num];
            ++freq[num - k];
            --freq[num + k + 1];
            freq[num];
        }

        int preSum = 0;
        for (const auto& [num, curCnt] : freq) {
            preSum += curCnt;
            if (cnt.count(num)) {
                ans = max(ans,  min(preSum, cnt[num] + numOperations));
            } else {
                ans = max(ans, min(preSum, numOperations));
            }
        }
        

        return ans;
    }
};





/* Official Solution 4 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0;
        unordered_map<int, int> numCount;
        set<int> modes;
        
        auto addMode = [&](int value) {
            modes.insert(value);
            if (value - k >= nums.front()) {
                modes.insert(value - k);
            }
            if (value + k <= nums.back()) {
                modes.insert(value + k);
            }
        };

        sort(nums.begin(), nums.end());
        
        for (int num : nums) {
            ++numCount[num];
        }

        for (const auto& [num, cnt] : numCount) {
            ans = max(ans, cnt);
            addMode(num);
        }


        for (int mode : modes) {
            int l = lower_bound(nums.begin(), nums.end(), mode - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), mode + k) - nums.begin();

            int tempAns;
            if (numCount.count(mode)) {
                tempAns = min(r - l, numCount[mode] + numOperations);
            } else {
                tempAns = min(r - l, numOperations);
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};
