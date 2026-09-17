/* Original Solution 1,  60 / 61 testcases passed */
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int firstStart;
        int firstEnd;

        auto getMinRange = [&](int start, int end) {
            int minRange = INT_MAX;
            int sum = 0;

            for (int left = start, right = start; right < end; right++) {
                sum += arr[right];

                while (sum > target) {
                    sum -= arr[left++];
                }

                if (sum == target) {
                    if (minRange > right - left + 1) {
                        minRange = right - left + 1;
                        firstStart = left;
                        firstEnd = right;
                    }
                    sum -= arr[left++];
                }
            }

            return minRange;
        };

        int firstMinRange = getMinRange(0, n);

        if (firstMinRange == INT_MAX) {
            return -1;
        }

        int start = firstStart;
        int end = firstEnd;

        int secondMinRange = getMinRange(0, start);
        secondMinRange = min(secondMinRange, getMinRange(end + 1, n));

        if (secondMinRange == INT_MAX) {
            return -1;
        }

        return firstMinRange + secondMinRange;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> pos;
        pos[0] = -1;
        int n = arr.size();
        int s = 0;
        int ans = n + 1;
        int minL = n;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            if (pos.count(s - target)) {
                int j = pos[s - target];
                int l = i - j;
                ans = min(ans, l + (j == -1 ? n : arr[j]));
                minL = min(minL, l);
            }
            arr[i] = minL;
            pos[s] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n + 1;
        int s = 0;
        vector<int> dp(n + 1, n);
        for (int l = 0, r = 0; r < n; r++) {
            s += arr[r];
            while (s > target) {
                s -= arr[l++];
            }
            dp[r + 1] = dp[r];
            if (s == target) {
                ans = min(ans, r - l + 1 + dp[l]);
                dp[r + 1] = min(dp[r], r - l + 1);
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};
