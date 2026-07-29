/* Original Solution 1 */
class Solution {
private:
    long long comb(long long n, long long m, long long k) {
        long long res = 1;
        m = std::min(m, n - m);

        for (long long i = 1; i <= m; i++) {
            res = res * (n - i + 1) / i;
            if (res > k) {
                return k + 1;
            }
        }
        return res;
    }

public:
    std::string smallestPalindrome(std::string s, long long k) {
        int partition = s.length() / 2;
        std::vector<int> bucket(26, 0);

        for (int i = 0; i < partition; i++) {
            bucket[s[i] - 'a'] += 1;
        }

        auto permutations = [&](int rem) {
            long long ways = 1;
            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) {
                    continue;
                }

                ways *= comb(rem, bucket[i], k);
                if (ways > k) {
                    break;
                }
                rem -= bucket[i];
            }
            return ways;
        };

        std::string left = "";
        long long startIndex = 1;

        for (int pos = 0; pos < partition; pos++) {
            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) {
                    continue;
                }

                bucket[i] -= 1;

                long long ways = permutations(partition - pos - 1);
                if (startIndex + ways > k) {
                    left += (char)(i + 'a');
                    break;
                }

                bucket[i] += 1;
                startIndex += ways;
            }
        }

        if (left.length() < partition) {
            return "";
        }

        std::string mid =
            s.length() % 2 != 0 ? std::string(1, s[partition]) : "";
        std::string right = left;
        std::reverse(right.begin(), right.end());

        return left + mid + right;
    }
};

/* Official Solution 2 */
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n / 2;

        int cnt[26]{};
        for (int i = 0; i < m; i++) {
            cnt[s[i] - 'a']++;
        }

        // 为什么这样做是对的？见 62. 不同路径 我的题解
        auto comb = [&](int n, int m) -> int {
            m = min(m, n - m);
            long long res = 1;
            for (int i = 1; i <= m; i++) {
                res = res * (n + 1 - i) / i;
                if (res >= k) { // 太大了
                    return k;
                }
            }
            return res;
        };

        // 计算长度为 sz 的字符串的排列个数
        auto perm = [&](int sz) -> int {
            long long res = 1;
            for (int c : cnt) {
                if (c == 0) {
                    continue;
                }
                // 先从 sz 个里面选 c 个位置填当前字母
                res *= comb(sz, c);
                if (res >= k) { // 太大了
                    return k;
                }
                // 从剩余位置中选位置填下一个字母
                sz -= c;
            }
            return res;
        };

        // k 太大
        if (perm(m) < k) {
            return "";
        }

        // 构造回文串的左半部分
        string left_s(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }
                cnt[j]--; // 假设填字母 j，看是否有足够的排列
                int p = perm(m - i - 1); // 剩余位置的排列个数
                if (p >= k) { // 有足够的排列
                    left_s[i] = 'a' + j;
                    break;
                }
                k -= p; // k 太大，要填更大的字母（类似搜索树剪掉了一个大小为 p 的子树）
                cnt[j]++;
            }
        }

        string ans = left_s;
        if (n % 2) {
            ans += s[n / 2];
        }
        ranges::reverse(left_s);
        return ans + left_s;
    }
};

/* Official Solution 3 */
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n / 2;

        int total[26]{};
        for (int i = 0; i < m; i++) {
            total[s[i] - 'a']++;
        }

        int cnt[26]{};
        long long perm = 1;
        int i = m - 1, j = 25;
        for (; i >= 0 && perm < k; i--) {
            while (cnt[j] == total[j]) {
                j--;
            }
            cnt[j]++;
            perm = perm * (m - i) / cnt[j];
        }

        if (perm < k) {
            return "";
        }

        string left_s;
        // 已经有足够的排列数了，<= i 的位置直接填字典序最小的排列
        for (int ch = 0; ch <= j; ch++) {
            left_s += string(total[ch] - cnt[ch], 'a' + ch);
        }

        // 试填法
        int j0 = j;
        for (i++; i < m; i++) {
            for (int j = j0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }
                // 假设填字母 j，根据 perm = p * (m - i) / cnt[j] 倒推 p
                long long p = perm * cnt[j] / (m - i);
                if (p >= k) {
                    left_s += 'a' + j;
                    cnt[j]--;
                    perm = p;
                    break;
                }
                k -= p;
            }
        }

        string ans = left_s;
        if (n % 2) {
            ans += s[n / 2];
        }
        ranges::reverse(left_s);
        return ans + left_s;
    }
};
