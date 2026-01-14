/* Official Solution 1 */
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while (n) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        int x = 31 - __builtin_clz(n);
        return (1 << (x + 1)) - 1 - minimumOneBitOperations(n - (1 << x));
    }
};

/* Official Solution 3 */
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int sign = 1;
        for (int i = 29; i >= 0; --i) {
            if (n & (1 << i)) {
                ans += sign * ((1 << (i + 1)) - 1);
                sign = -sign;
            }
        }
        return ans;
    }
};

/* Official Solution 4 */
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (!n) {
            return 0;
        }
        int x = 31 - __builtin_clz(n);
        // 第 x 位为 1
        int ans = 1 << x;
        // 二进制码的当前位
        int bit = 1;
        for (int i = x - 1; i >= 0; --i) {
            // 如果格雷码的第 i 位为 1，那么二进制码的当前位与上一个高位不相同
            if (n & (1 << i)) {
                bit ^= 1;
            }
            // 如果当前位为 1，将其加入答案
            if (bit) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
