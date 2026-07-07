/* Original Solution 1 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int sum = 0;
        const int decimal = 10;
        int multply = 1;
        int mod = 0;

        while (n != 0) {
            mod = n % decimal;

            if (mod != 0) {
                x += mod * multply;
                multply *= decimal;
            }
            sum += mod;
            n /= decimal;
        }

        return 1LL * x * sum;
    }
};


/* Official Solution 1 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        string s = to_string(n);
        for (char c : s) {
            int d = c - '0';
            sum += d;
            if (d > 0) {
                x = x * 10 + d;
            }
        }
        return x * sum;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, pow10 = 1;
        while (n > 0) {
            int d = n % 10;
            sum += d;
            if (d > 0) {
                x += d * pow10;
                pow10 *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};
