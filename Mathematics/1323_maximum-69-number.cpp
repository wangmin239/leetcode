/* Original Solution 1 */
class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        const int decimal = 10;

        while (num) {
            digits.push_back(num % decimal);
            num /= decimal;
        }
        

        bool isConverted = false;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            num *= decimal;
            if (isConverted == false && *iter == 6) {
                num += 3;
                isConverted = true;
            }
            num += *iter;
        }
        
        return num;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int maximum69Number (int num) {
        string digits(to_string(num));
        
        for (char& ch : digits) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }
        
        return stoi(digits);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maximum69Number (int num) {
        int digitBase = pow(10, (int)log10(num));
        while (digitBase > 0) {
            if ((num / digitBase) % 10 == 6) {
                num += 3 * digitBase;
                return num;
            }
            digitBase /= 10;
        }
        
        return num;
    }
};
