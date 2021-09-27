class Solution {
public:
    int numDecodings(string s) {
        int64_t dp[3] = {0}, half = 1, sum = 1;
        for(char c: s){
            if(c == '*'){
                tie(dp[0], dp[1], dp[2], half) = forward_as_tuple(sum * 7, sum, sum, dp[1] * 9 + dp[2] * 6);
            }
            else{
                int x = c - '0';
                half = (x < 7 ? dp[2] : 0) + dp[1]; 
                memset(dp, 0, sizeof(int64_t) * 3);
                dp[(x < 3) * x] = sum * !!x; //x为1,2时dp[x]=sum, x为3~9时dp[0]=sum, 为0时不变
            }
            sum = (dp[0] + dp[1] + dp[2] + half) % 1000000007;
        }
        return sum;
    }
};


class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int numDecodings(string s) {
        auto check1digit = [](char ch) -> int {
            if (ch == '0') {
                return 0;
            }
            return ch == '*' ? 9 : 1;
        };

        auto check2digits = [](char c0, char c1) -> int {
            if (c0 == '*' && c1 == '*') {
                return 15;
            }
            if (c0 == '*') {
                return c1 <= '6' ? 2 : 1;
            }
            if (c1 == '*') {
                if (c0 == '1') {
                    return 9;
                }
                if (c0 == '2') {
                    return 6;
                }
                return 0;
            }
            return c0 != '0' && (c0 - '0') * 10 + (c1 - '0') <= 26;
        };

        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; ++i) {
            c = (long long)b * check1digit(s[i - 1]) % mod;
            if (i > 1) {
                c = (c + (long long)a * check2digits(s[i - 2], s[i - 1])) % mod;
            }
            a = b;
            b = c;
        }
        return c;
    }
};
