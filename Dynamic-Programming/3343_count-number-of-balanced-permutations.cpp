/* Official Solution 1 */
class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<int> psum(11);
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
        long long memo[10][target + 1][maxOdd + 1];
        memset(memo, 0xff, sizeof(memo));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
        }

        function<long long(int, int, int)> dfs = [&](int pos, int curr, int oddCnt) -> long long {
            /* 如果剩余位置无法合法填充，或者当前奇数位置元素和大于目标值 */
            if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
                return 0;
            }
            if (pos > 9) {
                return curr == target && oddCnt == 0;
            }
            if (memo[pos][curr][oddCnt] != -1) {
                return memo[pos][curr][oddCnt];
            }
            /* 偶数位剩余需要填充的位数 */
            int evenCnt = psum[pos] - oddCnt;
            long long res = 0;
            for (int i = max(0, cnt[pos] - evenCnt); i <= min(cnt[pos], oddCnt); i++) {
                /* 当前数字在奇数位填充 i 位，偶数位填充 cnt[pos] - i 位 */
                long long ways = comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
                res = (res +  ways * dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) % MOD;
            }
            memo[pos][curr][oddCnt] = res;
            return res;
        };

        return dfs(0, 0, maxOdd);
    }
};


/* Official Solution 2 */
class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
        vector<vector<long long>> f(target + 1, vector<long long>(maxOdd + 1));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            /* 前 i 个数字的数目之和 */
            psum += cnt[i]; 
            /* 前 i 个数字的元素之和 */
            totSum += i * cnt[i];
            for (int oddCnt = min(psum, maxOdd); oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
                /* 偶数位需要填充的位数 */
                int evenCnt = psum - oddCnt;
                for (int curr = min(totSum, target); curr >= max(0, totSum - target); curr--) {
                    long long res = 0;
                    for (int j = max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        /* 当前数字在奇数位填充 j 位，偶数位填充 cnt[i] - j 位 */
                        long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return f[target][maxOdd];
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/count-number-of-balanced-permutations/solutions/3670620/tong-ji-ping-heng-pai-lie-de-shu-mu-by-l-ki3d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
作者：力扣官方题解
链接：https://leetcode.cn/problems/count-number-of-balanced-permutations/solutions/3670620/tong-ji-ping-heng-pai-lie-de-shu-mu-by-l-ki3d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。