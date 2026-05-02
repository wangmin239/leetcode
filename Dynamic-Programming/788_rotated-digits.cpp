/* Original Solution 1 */
class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        const int decimal = 10;

        for (int i = 1; i <= n; i++) {
            int num = i;
            int rotatedNum = 0;
            bool isRotated = true;
            int mulply = 1;

            while (num) {
                int mod = num % decimal;

                if (mod == 3 || mod == 4 || mod == 7) {
                    isRotated = false;
                    break;
                }

                num /= decimal;


                if (mod == 2 || mod == 6) {
                    mod += 3;
                } else if (mod == 5 || mod == 9) {
                    mod -= 3;
                }

                mod *= mulply;
                rotatedNum += mod;
                mulply *= decimal;
            }

            if (isRotated == true && rotatedNum != i) {
                ++cnt;
            }
        }

        return cnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        memset(memo, -1, sizeof(memo));
        function<int(int, bool, bool)> dfs = [&](int pos, bool bound, bool diff) -> int {
            if (pos == digits.size()) {
                return diff;
            }
            if (memo[pos][bound][diff] != -1) {
                return memo[pos][bound][diff];
            }

            int ret = 0;
            for (int i = 0; i <= (bound ? digits[pos] : 9); ++i) {
                if (check[i] != -1) {
                    ret += dfs(
                        pos + 1,
                        bound && (i == digits[pos]),
                        diff || (check[i] == 1)
                    );
                }
            }
            return memo[pos][bound][diff] = ret;
        };
        
        int ans = dfs(0, true, false);
        return ans;
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
    int memo[5][2][2];
};

