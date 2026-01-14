/* Official Solution 1 */
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                ans -= i;
            } else {
                ans += i;
            }
        }
        return ans;
    }
};



/* Original Solution 1 */
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int diff = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m != 0) {
                diff += i;
            } else {
                diff -= i;
            }
        }

        return diff;
    }
};