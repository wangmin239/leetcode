/* Original Solution 1 */
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> diff(n + 1, 0);
        
        /* Calculate the interval between two consecutive meetings */
        diff[0] = startTime[0];
        diff[n] = eventTime - endTime.back();
        for (int i = 1; i < n;  i++) {
            diff[i] = startTime[i] - endTime[i - 1];
        }
        
        /* Compare the sum of each group of K consecutive intervals */
        int maxDiff = accumulate(diff.begin(), diff.begin() + k + 1, 0);
        int preSum = maxDiff;
        for (int i = k + 1; i < n + 1; i++) {
            preSum = preSum + diff[i] - diff[i - k - 1];
            maxDiff = max(maxDiff, preSum);
        }
        
        return maxDiff;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + endTime[i] - startTime[i];
        }
        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            int left = i == k - 1 ? 0 : endTime[i - k];
            res = max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = max(res, right - left - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return res;
    }
};
