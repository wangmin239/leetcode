class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0 || n == 1) {
            return to_string(n);
        }
        string res;
        while (n != 0) {
            int remainder = n & 1;
            res.push_back('0' + remainder);
            n -= remainder;
            n /= -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        vector<int> bits(32);
        for (int i = 0; i < 32 && n != 0; i++) {
            if (n & 1) {
                bits[i]++;
                if (i & 1) {
                    bits[i + 1]++;
                }
            }
            n >>= 1;
        }
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int val = carry + bits[i];
            bits[i] = val & 1;
            carry = (val - bits[i]) / (-2);
        }
        int pos = 31;
        string res;
        while (pos >= 0 && bits[pos] == 0) {
            pos--;
        }
        while (pos >= 0) {
            res.push_back(bits[pos] + '0');
            pos--;
        }
        return res;
    }
};


class Solution {
public:
    string baseNeg2(int n) {
        int val = 0x55555555 ^ (0x55555555 - n);
        if (val == 0) {
            return "0";
        }
        string res;
        while (val) {
            res.push_back('0' + (val & 1));
            val >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        string str;
   
        backTrace(n, 0, str, 0); 
        
        
        return str;
    }
    
    
    bool backTrace(int n, int len, string& str,  long sum) {
　       if (sum == n) {
            return true;
         }
         
         if (len > 31) {
            return false;
         }

        int step = static_cast<int>(pow(-2, len));
        if (backTrace(n, len + 1, str, sum + step) == true) {
            str.append("1") ;
            return true;
        }
        
        if (backTrace(n, len + 1, str, sum) == true) {
            str.append("0");
            return true;
        }
         
        return false;   
    }
};