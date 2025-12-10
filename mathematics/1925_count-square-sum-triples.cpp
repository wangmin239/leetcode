/* Official Solution 1 */
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        unordered_set<int> nums;


        for (int i = 1; i <= n; i++) {
            nums.insert(i * i);
        }

        for (int first : nums) {
            for (int second : nums) {
                int squareSum = first + second;

                if (nums.count(squareSum) != 0) {
                    ++cnt;
                }

            }
        }

        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int u = 3; u * u < n * 2; u += 2) {
            for (int v = 1; v < u && u * u + v * v <= n * 2; v += 2) {
                if (gcd(u, v) == 1) {
                    ans += n * 2 / (u * u + v * v);
                }
            }
        }
        return ans * 2; // (a,b,c) 和 (b,a,c) 各算一次
    }
};


/* Official Solution 2 */
constexpr int MX = 23; // floor(sqrt(250 * 2)) + 1
int mu[MX];
vector<int> divisors[MX];

int init = [] {
    // 预处理莫比乌斯函数
    // 当 n > 1 时，sum_{d|n} mu[d] = 0
    // 所以 mu[n] = -sum_{d|n ∧ d<n} mu[d]
    mu[1] = 1;
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            mu[j] -= mu[i]; // i 是 j 的真因子
        }
    }

    // 预处理不含平方因子的因子列表，用于 count_coprime
    for (int i = 1; i < MX; i++) {
        if (mu[i]) {
            for (int j = i; j < MX; j += i) {
                divisors[j].push_back(i); // i 是 j 的因子，且 mu[i] != 0
            }
        }
    }
    return 0;
}();

class Solution {
    // 返回 [1,n] 中与 x 互质的整数个数
    int count_coprime(int n, int x) {
        int res = 0;
        for (int d : divisors[x]) {
            res += mu[d] * (n / d);
        }
        return res;
    }

    // 返回 [1,n] 中与奇数 x 互质的奇数个数
    // 与 x 互质的整数个数 - 与 x 互质的偶数个数
    int count_coprime_odd(int n, int x) {
        return count_coprime(n, x) - count_coprime(n / 2, x);
    }

public:
    int countTriples(int n) {
        int ans = 0;
        for (int u = 3; u * u < n * 2; u += 2) {
            for (int l = 1, r; l < u && u * u + l * l <= n * 2; l = r + 1) {
                int num = (n * 2) / (u * u + l * l);
                // 对于 [l,r] 中的整数 v，floor(2n / (u^2 + v^2)) 都等于 num
                r = min((int) sqrt(n * 2 / num - u * u), u - 1); // 推导过程见题解
                // 只有与 u 互质的奇数 v 才能得到本原勾股数组
                int num_coprime_odd_v = count_coprime_odd(r, u) - count_coprime_odd(l - 1, u);
                ans += num * num_coprime_odd_v;
            }
        }
        return ans * 2; // (a,b,c) 和 (b,a,c) 各算一次
    }
};




/* Official Solution 3 */
class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        // 枚举 a 与 b
        for (int a = 1; a <= n; ++a){
            for (int b = 1; b <= n; ++b){
                // 判断是否符合要求
                int c = int(sqrt(a * a + b * b + 1.0));
                if (c <= n && c * c == a * a + b * b){
                    ++res;
                }
            }
        }
        return res;
    }
};
