/* Original Solution 1 */
class Solution {
public:
    int smallestNumber(int n) {
        int val = 0;
        
        for (int i = 0; n != 0; i++) {
            val += (1 << i);
            n >>= 1;
        }
        
        return val;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int smallestNumber(int n) {
        return (1 << bit_width((uint32_t) n)) - 1;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int smallestNumber(int n) {
        return (1 << (32-__builtin_clz(n))) - 1;
    }
};