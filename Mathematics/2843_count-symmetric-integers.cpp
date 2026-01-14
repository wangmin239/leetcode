class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        const int limit = 5;
        
        while (low <= high) {
            int digit[limit] = {0};
            int value = low++;
            int i;
            
            for (i = 0; i < limit && value; i++) {
                digit[i] = value % 10;
                value /= 10;
            }
            
            /* check if is odd */
            if (i & 0x1) {
                continue;
            }
            
            /* Check if meet requirements */
            cnt += accumulate(digit, digit + limit, 0) == 2 * accumulate(digit, digit + i / 2, 0);
        }
        
        return cnt;
    }
};


class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int a = low; a <= high; ++a) {
            if (a < 100 && a % 11 == 0) {
                res++;
            } else if (1000 <= a && a < 10000) {
                int left = a / 1000 + (a % 1000) / 100;
                int right = (a % 100) / 10 + a % 10;
                if (left == right) {
                    res++;
                }
            }
        }
        return res;
    }
};
