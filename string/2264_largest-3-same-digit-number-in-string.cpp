class Solution {
public:
    string largestGoodInteger(string num) {
        char digit = '0';
        int len = num.length();
        bool isThree = false;
        const int limit = 3;

        for (int i = 0; i < len - limit + 1; i++) {
            /* Check if three consecutive characters are the same */
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                digit = max(digit, num[i]);
                isThree = true;
            }
          
        }
        
        return isThree? string(limit, digit) : "";
    }
};



class Solution {
public:
    string largestGoodInteger(string num) {
        char digit = '0';
        int len = num.length();
        const int limit = 3;
        bool isThree = false;

        for (int i = 0; i < len; i++) {
            int cnt = 1;
            /* Check if three consecutive characters are the same */
            for (int j = 1; j < limit && i + j < len; j++) {
                cnt += static_cast<int>(num[i] == num[i + j]);
            }
            
            if (cnt == limit) {
                digit = max(digit, num[i]);
                i += limit - 1;
                isThree = true;
            }
        }
        
        return isThree? string(limit, digit) : "";
    }
};

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res;
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                res = max(res, num.substr(i, 3));
            }
        }
        return res;
    }
};
