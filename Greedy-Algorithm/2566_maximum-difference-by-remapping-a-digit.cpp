/* Original Solution 1 */
class Solution {
public:
    int minMaxDifference(int num) {
        const int decimal = 10;
        int digit[decimal] = {0};
        int i  = 0;
        
        while (num) {
            digit[i++] = num % decimal;
            num /= decimal;
        }
        int mostBit = i;
        int maxVal = 0;
        int high = decimal - 1;
        
        while (i--) {
            maxVal *= decimal;
            if (digit[i] == high) {
                maxVal += decimal - 1;
                continue;
            }
            if (high == decimal - 1) {
                high = digit[i];
                maxVal += decimal - 1;
                continue;
            } 
            maxVal += digit[i];

        }
        
        i = mostBit;
        high = digit[i - 1];
        int minVal = 0;
        while (i--) {
            minVal *= decimal;
            if (digit[i] != high) {
                minVal += digit[i];
            }
        }
        
        return maxVal - minVal;

    }
};

/* Original Solution 2 */
class Solution {
public:
    int minMaxDifference(int num) {
        string digit(to_string(num));
        string maxStr(digit);
        string minStr(digit);

        char first = digit.front();
        for (size_t i = 0; i < minStr.length(); i++) {
            if (minStr[i] == first) {
                minStr[i] = '0';
            }
        }

        first = '9';
        for (size_t i = 0; i < maxStr.length(); i++) {
            if (maxStr[i] == '9') {
                continue;
            } 

            if (first == '9') {
                first = maxStr[i];
                maxStr[i] = '9';
            } else if (maxStr[i] == first) {
                maxStr[i] = '9';
            }
        }

        return stoi(maxStr) - stoi(minStr);


    }
};

/* Official Solution 1 */
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};
