/* Original Solution 1 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
       int pre = n & 0x1;

       while (n) {
         n >>= 0x1;
         int cur = n & 0x1;
         if ((cur ^ pre) != 0x1) {
             return false;
         }
         pre = cur;
       }

       return true;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};

