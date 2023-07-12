class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;   
        int signal = -1;
        auto calc = [&](int n) {
            while (n != 0) {
                int mod = n % 10;
                sum += mod * signal;
                signal *= -1;
                n /= 10;
            }
        };
        calc(n);
        if (signal == -1) {
            return sum;
        }
        signal = 1;
        sum = 0;
        calc(n);
        return sum;
    }
};


class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1;
        while (n > 0) {
            res += n % 10 * sign;
            sign = -sign;
            n /= 10;
        }
        return -sign * res;
    }
};

