class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        return string(cnt - 1, '1') + string(s.length() - cnt, '0') + '1';
    }
};



class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int oneCnt = 0;

        
        /* statistic the number of the digit '1' */
        for (char& ch : s) {
            if (ch - '0' == 1) {
                ++oneCnt;
            }
            ch = '1';
        }
        
        /* replace '1' with '0' */
        for (int i = oneCnt - 1; i < n - 1; i++) {
            s[i] = '0';
        }
        return s;
    }
};


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int oneCnt = 0;
        string ans(n, '1');
        
        /* statistic the number of the digit '1' */
        for (char ch : s) {
            if (ch - '0' == 1) {
                ++oneCnt;
            }
        }
        
        /* replace '1' with '0' */
        for (int i = oneCnt - 1; i < n - 1; i++) {
            ans[i] = '0';
        }
        return ans;
    }
};


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int oneCnt = 0;
        
        for (char ch : s) {
            if (ch - '0' == 1) {
                ++oneCnt;
            }
        }
        
        if (oneCnt == 1) {
            return string(n - 1, '0') + "1";
        }
        
        return string(oneCnt - 1, '1') + string(n - oneCnt, '0') + "1";
    }
};