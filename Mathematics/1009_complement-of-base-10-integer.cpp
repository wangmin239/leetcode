/* Original Solution 1 */
class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;

        if (n == 0) {
            return 1;
        }

        for (int i = 0; n != 0; i++) {
            ans |= (!(n & 1)) << i;
            n >>= 1;
        }

        return ans;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int bitwiseComplement(int n) {
        int exp = bit_width(static_cast<unsigned int>(n));

        exp = exp == 0 ? 1: exp;
        return ((1 << exp) - 1) ^ n;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int bitwiseComplement(int n) {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i) {
            if (n >= (1 << i)) {
                highbit = i;
            }
            else {
                break;
            }            
        }
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        return n ^ mask;
    }
};
