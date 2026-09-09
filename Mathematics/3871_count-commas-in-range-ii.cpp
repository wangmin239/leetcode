/* Original Solution 1 */
class Solution {
public:
    long long countCommas(long long n) {
        const int thousand = 1000;
        long long ans = 0;
        long long bakN(n);
        int turns = 1;

        auto getPow = [](const int base , int exp) {
            long long multple = 1LL;

            while (exp--) {
                multple *= base;

            }

            return multple;
        }

        while (bakN / thousand) {
            ans += n + 1 - getPow(thousand, turns);
            bakN /= thousand;

            ++turns;
        }

        return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    long long countCommas(long long n) {
        int ans = 0;
        const int thousand = 1000;
        auto dfs = [&](long long remain, long long powVal, auto&& self) {

            if (remain < thousand) {
                return 0LL;
            }

            return n + 1 - powVal + self(remain / thousand, powVal * thousand, self);
        };

        return dfs(n, thousand, dfs);
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        // 从低到高，枚举逗号的位置
        for (long long low = 1000; low <= n; low *= 1000) {
            // [low, n] 中的每个数都在这个位置上有一个逗号
            ans += n - low + 1;
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000, res = 0;
        while (p <= n) {
            res += n - p + 1;
            p *= 1000;
        }
        return res;
    }
};
