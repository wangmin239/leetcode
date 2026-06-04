/* Original Solution 1 */
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        const int decimal = 10;
        const int maxLen = 5;
        auto getWave = [decimal](int num) {
            if (num <= 100) {
                return 0;
            }

            string digitStr(maxLen, '0');
            int len;

            for (len = 0; num != 0; num /= decimal) {
                digitStr[len++] += num % decimal;
            }

            int waveCnt = 0;

            for (int i = 1; i < len - 1; i++) {
                if (digitStr[i] > digitStr[i - 1] && digitStr[i] > digitStr[i + 1]) {
                    ++waveCnt;
                    continue;
                }

                if (digitStr[i] < digitStr[i - 1] && digitStr[i] < digitStr[i + 1]) {
                    ++waveCnt;
                }
            }
            return waveCnt;
        };

        int sum = 0;
        for (int i = num1; i <= num2; i++) {
            sum += getWave(i);
        }

        return sum;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto getWaviness = [](int x) -> int {
            string s = to_string(x);
            int waviness = 0;
            
            for (size_t i = 1; i < s.size() - 1; ++i) {
                bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
                bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
                if (isPeak || isValley) {
                    ++waviness;
                }
            }
            
            return waviness;
        };

        int total = 0;
        for (int i = num1; i <= num2; ++i) {
            total += getWaviness(i);
        }

        return total;
    }
};
