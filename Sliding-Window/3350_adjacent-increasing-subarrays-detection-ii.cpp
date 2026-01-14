/* Original Solution 1 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxK = 1, cnt = 1;
        int preCnt = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                ++cnt;
            } else {
                maxK = max(maxK, min(preCnt, cnt));
                maxK = max(maxK, cnt / 2);
                preCnt = cnt;
                cnt = 1;
            }
        }

        maxK = max(maxK, min(preCnt, cnt));
        maxK = max(maxK, cnt / 2);


        return maxK;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxK = 1, cnt = 1;
        int preCnt = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                ++cnt;
            } else {
                preCnt = cnt;
                cnt = 1;
            }

            maxK = max(maxK, min(preCnt, cnt));
            maxK = max(maxK, cnt / 2);
        }

        return maxK;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
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
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxIncreasingSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        auto check = [&](int mid) {
            for (int i = mid; i < n; i++) {
                if (dp[i - mid] >= mid && dp[i] >= mid) {
                    return true;
                }
            }
            return false;
        };

        int l = 1;
        int r = n / 2 + 2;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return check(l) ? l : l - 1;
    }
};