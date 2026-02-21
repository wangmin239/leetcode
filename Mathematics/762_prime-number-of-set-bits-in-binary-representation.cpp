/* Original Solution 1 */
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> prime {2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;

        for (unsigned int i = left; i <= right; i++) {
            int num = popcount(i);
            if (prime.count(num)) {
                ++ans;
            }
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};
