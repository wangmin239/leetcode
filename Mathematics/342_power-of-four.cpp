
/* Original Solution 1 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) {
            return false;
        }
        
        const int maxExponent = 15;
        const int base = 4;
        const int sum = (1LL * base * static_cast<int>(pow(base, maxExponent)) - 1) / (base - 1);
        
        int andSum = n & sum;
        int orSum = n | sum;
        int ones = __builtin_popcount(sum);
        
        return __builtin_popcount(andSum) == 1 && __builtin_popcount(orSum) == ones;
    }
};
