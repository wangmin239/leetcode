class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevDigit = 0;
        int curDigit = 0;
        
        
        curDigit = n % 2;
        n /= 2;
        while (n > 0) {
            prevDigit = curDigit;
            curDigit = n % 2;
            n /= 2;
            if ((prevDigit ^ curDigit) != 1) {
                return false;
            }
        }
        
        return prevDigit ^ curDigit;
    }
};


class Solution {
public:
    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = 2;
        while (n != 0) {
            int cur = n % 2;
            if (cur == prev) {
                return false;
            }
            prev = cur;
            n /= 2;
        }
        return true;
    }
};
