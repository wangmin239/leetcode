/* Original Solution 1 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int flag = 1;
        int len = nums.size();
        int cnt = 1;

        for (int i = 1, j = 0; i < len; i++) {
            if (flag > 0 && nums[i] > nums[i - 1]) {
                cnt = max(cnt, i - j + 1);
                continue;
            }

            if (flag < 0 && nums[i] < nums[i - 1]) {
                cnt = max(cnt, i - j + 1);
                continue;
            }

            if (nums[i] == nums[i - 1]) {
                j = i;
                flag = 1;
                continue;
            }

            if (flag * (nums[i] - nums[i - 1]) < 0) {
                flag = -flag;
                j = i - 1;
                cnt = max(cnt, 2);
            }
        }

        return cnt;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = nums.size();

        auto getMaxLen = [len](vector<int>& nums, int flag) {
            int cnt = 1;

            for (int i = 1, j = 0; i < len; i++) {
                if (flag) {
                    if (nums[i] > nums[i - 1]) {
                        cnt = max(cnt, i - j + 1);
                    } else {
                        j = i;
                    }
                } else {
                    if (nums[i] < nums[i - 1]) {
                        cnt = max(cnt, i - j + 1);
                    } else {
                        j = i;
                    }
                }
            }

            return cnt;
        };

        return max(getMaxLen(nums, 1), getMaxLen(nums, 0));
    }
};


/* Official Solution 1 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int> &nums) {
        int ans = 1;
        int i = 0;
        int n = nums.size();
        while (i < n - 1) {
            if (nums[i + 1] == nums[i]) {
                i++;
                continue;
            }
            int j = i;
            bool inc = nums[i + 1] > nums[i];
            i += 2;
            while (i < n && nums[i] != nums[i - 1] && (nums[i] > nums[i - 1]) == inc) {
                i++;
            }
            ans = max(ans, i - j);
            i--;
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1 = 1, cnt2 = 1;
        int ans = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, cnt1);
                cnt1 = 1;
            } else {
                cnt1++;
            }
            if (nums[i] >= nums[i - 1]) {
                ans = max(ans, cnt2);
                cnt2 = 1;
            } else {
                cnt2++;
            }
        }
        ans = max(ans, max(cnt1, cnt2));
        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int> &a) {
        int ans = 1;
        int i = 0, n = a.size();
        while (i < n - 1) {
            if (a[i + 1] == a[i]) {
                i++; // 直接跳过
                continue;
            }
            int start = i; // 记录这一组的开始位置
            bool inc = a[i] < a[i + 1]; // 定下基调：是严格递增还是严格递减
            i += 2; // i 和 i+1 已经满足要求，从 i+2 开始判断
            while (i < n && a[i] != a[i - 1] && (a[i] > a[i - 1]) == inc) {
                i++;
            }
            // 从 start 到 i-1 是满足题目要求的（并且无法再延长的）子数组
            ans = max(ans, i - start);
            i--;
        }
        return ans;
    }
};
