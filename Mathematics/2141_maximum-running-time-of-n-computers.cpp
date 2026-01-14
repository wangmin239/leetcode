/* Official Solution 1 */
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long tot = reduce(batteries.begin(), batteries.end(), 0LL);
        long long l = 0, r = tot / n + 1;
        while (l + 1 < r) {
            long long x = l + (r - l) / 2;
            long long sum = 0;
            for (long long b : batteries) {
                sum += min(b, x);
            }
            (n * x <= sum ? l : r) = x;
        }
        return l;
    }
};



/* Official Solution 2 */
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ranges::sort(batteries, greater());
        long long sum = reduce(batteries.begin(), batteries.end(), 0LL);
        for (int i = 0; ; i++) {
            if (batteries[i] <= sum / n) {
                return sum / n;
            }
            sum -= batteries[i];
            n--;
        }
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n, ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long total = 0;
            for (int cap: batteries) {
                total += min(static_cast<long long>(cap), mid);
            }
            if (total >= n * mid) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
