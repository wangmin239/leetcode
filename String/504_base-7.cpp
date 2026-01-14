class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool isNegative = false;
        
        if (num < 0) {
            isNegative = true;
            num = num * (-1);
        }
        
        do {
            ans.push_back(static_cast<char>('0' + num % 7));
            num /= 7;
        } while (num != 0);
        
        if (isNegative == true) {
            ans.push_back('-');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool negative = num < 0;
        num = abs(num);
        string digits;
        while (num > 0) {
            digits.push_back(num % 7 + '0');
            num /= 7;
        }
        if (negative) {
            digits.push_back('-');
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
