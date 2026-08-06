/* Original Solution 1 */
class Solution {
public:
    int smallestNumber(int n, int t) {
        const int decimal = 10;
        int ans, mul, num;

        while (true) {
            mul = 1;
            num = n;

            while (num) {
               mul *= num % decimal;
               num /= decimal;
            }

            if (mul % t == 0) {
                ans = n;
                break;
            }
            ++n;

        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int smallestNumber(int n, int t) {
        auto check = [&](int num) -> bool {
            int product = 1;
            while (num) {
                product *= (num % 10);
                num /= 10;
                if (!product) {
                    break;
                }
            }
            return !(product % t);
        };
        while (!check(n)) {
            n++;
        }
        return n;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            int prod = 1;
            for (int x = i; x; x /= 10) {
                prod *= x % 10;
            }
            if (prod % t == 0) {
                return i;
            }
        }
    }
};
