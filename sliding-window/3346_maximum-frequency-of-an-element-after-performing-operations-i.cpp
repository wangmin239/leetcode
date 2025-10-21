/* Official Solution 1 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        unordered_map<int, int> numCount;

        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);

        auto leftBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        for (int i = nums.front(); i <= nums.back(); i++) {
            int l = leftBound(i - k);
            int r = rightBound(i + k);

            int tempAns;
            if (numCount.count(i)) {
                tempAns = min(r - l + 1, numCount[i] + numOperations);
            } else {
                tempAns = min(r - l + 1, numOperations);
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        unordered_map<int, int> numCount;

        int lastNumIndex = 0;
        for (int num : nums) {
            ans = max(ans, ++numCount[num]);
        }

        for (int i = nums.front(); i <= nums.back(); i++) {
            int l = lower_bound(nums.begin(), nums.end(), i -k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin();

            int tempAns;
            if (numCount.count(i)) {
                tempAns = min(r - l, numCount[i] + numOperations);
            } else {
                tempAns = min(r - l, numOperations);
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> diff;
        for (int x : nums) {
            cnt[x]++;
            diff[x]; // 把 x 插入 diff，以保证下面能遍历到 x
            diff[x - k]++; // 把 [x-k, x+k] 中的每个整数的出现次数都加一
            diff[x + k + 1]--;
        }

        int ans = 0, sum_d = 0;
        for (auto& [x, d] : diff) {
            sum_d += d;
            ans = max(ans, min(sum_d, cnt[x] + numOperations));
        }
        return ans;
    }
};


/* Official Solution 4 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        ranges::sort(nums);

        int n = nums.size();
        int ans = 0, left = 0, right = 0, left2 = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (nums[left2] < x - k * 2) {
                left2++;
            }
            ans = max(ans, min(i - left2 + 1, numOperations));

            // 循环直到连续相同段的末尾，这样可以统计出 x 的出现次数
            if (i < n - 1 && x == nums[i + 1]) {
                continue;
            }
            left = left2;
            while (nums[left] < x - k) {
                left++;
            }
            while (right < n && nums[right] <= x + k) {
                right++;
            }
            ans = max(ans, min(right - left, 1 + numOperations));

        }

        return ans;
    }
};

/* Official Solution 5 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
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

        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                addMode(nums[lastNumIndex]);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);
        addMode(nums[lastNumIndex]);

        auto leftBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        for (int mode : modes) {
            int l = leftBound(mode - k);
            int r = rightBound(mode + k);

            int tempAns;
            if (numCount.count(mode)) {
                tempAns = min(r - l + 1, numCount[mode] + numOperations);
            } else {
                tempAns = min(r - l + 1, numOperations);
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};
