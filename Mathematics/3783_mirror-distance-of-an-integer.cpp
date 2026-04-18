/* Original Solution 1 */
class Solution {
public:
    int mirrorDistance(int n) {
        auto reverse = [](int num) {
            int value = 0;
            const int decimal = 10;

            while (num != 0) {
                value *= decimal;
                value += num % decimal;
                num /= decimal;
            }

            return value;
        };

        return abs(n - reverse(n));

    }
};