/* Original Solution 1 */
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        const int decimal = 10;
        int bakVal(n);

        while (n) {
            int digit = n % decimal;

            sum += digit;
            mul *= digit;

            n /= decimal;
        }

        return bakVal % (sum + mul) == 0;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int original = n;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            digitSum += digit;
            digitProduct *= digit;
        }

        return original % (digitSum + digitProduct) == 0;
    }
};
