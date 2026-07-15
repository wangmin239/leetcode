/* Original Solution 1 */
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        int limit = (n << 1) + 1;
        const int step = 2;

        for (int i = 1; i < limit; i += 2) {
            sumOdd += i;
            sumEven += i + 1;
        }

        return gcd(sumOdd, sumEven);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    int gcdOfOddEvenSums(int n) {
        return gcd(n * n, n * (n + 1));
    }
};

