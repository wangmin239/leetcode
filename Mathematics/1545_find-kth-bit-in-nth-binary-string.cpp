/* Original Solution 1 */
class Solution {
public:
    char findKthBit(int n, int k) {
        string bitStr("0");

        auto reverse = [](string& str) {
            for (int left = 0, right = str.length() - 1; left < right; left++, right--) {
                swap(str[left], str[right]);
            }
        };

        auto invert = [](string& str) {
            for (char& ch : str) {
                ch = '0' + !(ch - '0');
            }

            return;
        };

        for (int i = 1; i < n; i++) {
            string nextStr(bitStr + "1");

            invert(bitStr);
            reverse(bitStr);
            nextStr += bitStr;
            bitStr = nextStr;
        }

        return bitStr[k - 1];
    }
};

/* Official Solution 1 */
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1) {
            return '0';
        }
        int mid = 1 << (n - 1);
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            k = mid * 2 - k;
            return invert(findKthBit(n - 1, k));
        }
    }

    char invert(char bit) {
        return (char) ('0' + '1' - bit);
    }
};


/* Official Solution 2 */
class Solution {
public:
    char findKthBit(int, int k) {
        if (k % 2) {
            return '0' + k / 2 % 2;
        }
        k /= k & -k; // 去掉 k 的尾零
        return '1' - k / 2 % 2;
    }
};


/* Official Solution 3 */
class Solution {
public:
    char findKthBit(int n, int k) {
        int rev = 0; // 翻转次数的奇偶性
        while (true) {
            if (n == 1) {
                return '0' ^ rev;
            }
            if (k == 1 << (n - 1)) {
                return '1' ^ rev;
            }
            if (k > 1 << (n - 1)) {
                k = (1 << n) - k;
                rev ^= 1;
            }
            n--;
        }
    }
};
