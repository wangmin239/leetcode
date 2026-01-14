class Solution {
public:
    long long minEnd(int n, int x) {
        int bitCount = 64 - __builtin_clz(n) - __builtin_clz(x);
        long long res = x;
        long long m = n - 1;
        int j = 0;
        for (int i = 0; i < bitCount; ++i) {
            if (((res >> i) & 1) == 0) {
                if ((m >> j) & 1) {
                    res |= (1LL << i);
                }
                j++;
            }
        }
        return res;
    }
};


class Solution {
public:
    long long minEnd(int n, int x) {
        int bitCount = 64 - __builtin_clz(n) - __builtin_clz(x);
        long long res = x;
        int j = 0;
        
        /* the variable 'n' using the integer type will cause overflow */
        long long m = n - 1;
        
        for (int i = 0; i < bitCount; i++) {
            if (((res >> i) & 0x1) == 0) {
                res |= ((m >> j) & 0x1) << i;
                ++j;
            }
        }
        
        return res;
    }
};




class Solution {
public:
    long long minEnd(int n, int x) {
        int oneCnt = __builtin_popcount(x);
        int shift = 32 - __builtin_clz(x);
        int zeroCnt = shift - oneCnt;
        
        /* Calculating the number of one period */
        int methods = pow(2, zeroCnt);
        long long hiVal = n / methods;
        int loVal = n % methods;

        hiVal <<= shift;
        
      
        if (loVal == 0) {
            return hiVal - 1;
        }
        
        if (loVal == 1) {
            return hiVal | x;
        }

        int ans = x;
        int i = 0;
        
        /* replenish the zero bits with one binary value of the remain data */
        loVal -= 1;
        while (loVal) {
            if (((x >> i) & 0x1) == 0) {
                ans |= (loVal & 0x1) << i;
                loVal >>= 1;
            }
            ++i;
        }
        
        return hiVal | ans;
    }
};

