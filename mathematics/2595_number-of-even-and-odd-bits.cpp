/* Original Solution */
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        
        for (int bit = 0; n != 0; bit++, n >>= 1) {
            if (n & 1) {
                ++ans[bit & 0x1];
            }
        }
        
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res = {0, 0};
        int i = 0;
        while (n) {
            res[i] += n & 1;
            n >>= 1;
            i ^= 1;
        }
        return res;
    }
};
