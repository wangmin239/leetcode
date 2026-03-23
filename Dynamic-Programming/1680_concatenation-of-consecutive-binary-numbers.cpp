/* Original Solution 1 */
class Solution {
public:
    int concatenatedBinary(int n) {
        auto&& numToBin = [](int value) {
            string binaryStr;
            const int mod = 2;

            while (value) {
                binaryStr.push_back('0' + value % mod);
                value /= mod;
            }

            return binaryStr;
        };

        string binaryStr;
        constexpr int mod = 1e9 + 7;

        for (int i = n; i > 0; i--) {
            binaryStr.append(numToBin(i));
        }

        int len = binaryStr.length();
        long long remain = 0;
        const int exponent = 30;
        constexpr int binMod = (1 << exponent) % mod;
        unordered_map<int, int> modMap;
        modMap[0] = 1;

        for (int i = 0; i < len; i++) {
            if (binaryStr[i] == '0') {
                continue;
            }

            int remainExp = i % exponent;
            int mulExp = i / exponent;
            long long curRemain;

            if (modMap.count(mulExp) == 0) {
                modMap[mulExp] = 1LL * modMap[mulExp - 1] * binMod % mod;
            }
            curRemain = modMap[mulExp];
            curRemain *= 1LL << remainExp;

            remain += curRemain;
            remain %= mod;
        }

        return remain;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int concatenatedBinary(int n) {
        long long remain = 0, curRemain;
        const int exponent = 30;
        constexpr int mod = 1e9 + 7;
        constexpr int binMod = (1 << exponent) % mod;
        unordered_map<int, int> modMap;

        modMap[0] = 1;
        for (int val = n, i = 0; val > 0; val--) {
            for (int num = val; num != 0; ++i, num >>= 1) {
                if ((num & 0x1) == 0) {
                    continue;
                }

                int remainExp = i % exponent;
                int mulExp = i / exponent;

                if (modMap.count(mulExp) == 0) {
                    modMap[mulExp] = modMap[mulExp - 1] * binMod % mod;
                }
                curRemain = modMap[mulExp];
                curRemain *= 1 << remainExp;

                remain += curRemain;
                remain %= mod;
            }
        }

        return remain;
    }
};

/* Official Solution 1 */
class Solution {
private:
    static constexpr int mod = 1000000007;
    
public:
    int concatenatedBinary(int n) {
        // 
        int ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            // if (131072 % i == 0) {
            if (!(i & (i - 1))) {
                ++shift;
            }
            ans = ((static_cast<long long>(ans) << shift) + i) % mod;
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int concatenatedBinary(int n) {
        constexpr int MOD = 1'000'000'007;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int w = bit_width((uint32_t) i);
            ans = (ans << w | i) % MOD;
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
    static constexpr int MOD = 1'000'000'007;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int w = 1; 1 << (w - 1) <= n; w++) {
            int l = 1 << (w - 1);
            int r = min((1 << w) - 1, n);
            int m = r - l + 1;
            int q = 1 << w;
            long long pow_q = pow(q, m);
            long long inv_q1 = pow(q - 1, MOD - 2);
            long long s = r * (pow_q - 1) % MOD * inv_q1 - (q - m * pow_q + (m - 1) * pow_q % MOD * q) % MOD * inv_q1 % MOD * inv_q1;
            ans = (ans * pow_q + s) % MOD;
        }
        return (ans + MOD) % MOD; // 保证结果非负
    }
};
