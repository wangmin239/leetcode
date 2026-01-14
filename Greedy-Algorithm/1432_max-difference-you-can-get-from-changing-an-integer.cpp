/* Original Solution 1 */
class Solution {
public:
    int maxDiff(int num) {
        const int decimal = 10;
        int digit[decimal] = {0};
        int i = 0;
        
        while (num) {
            digit[i++] = num % decimal;
            num /= decimal;
        }
        
        int mostBit = i;
        int maxVal = 0;
        int high = decimal - 1;
        /* get the maximal value */
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
        /* Get the minimal value */
        int minVal = 1;
        bool isOne = false;
        i = mostBit - 1;
        
        if (digit[i] != 1) {
            high = digit[i];
        } else {
            high = decimal;
        }
        
        while (i--) {
            minVal *= decimal;
            if (digit[i] < 2) {
                minVal += digit[i];
                continue;
            }
            
            if (high == decimal) {
                high = digit[i];
                isOne = true;
                continue;
            }
            
            if (digit[i] == high) {
                minVal += static_cast<int>(!isOne);
                continue;
            }
            minVal += digit[i];
        }
        return  maxVal - minVal ;  
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxDiff(int num) {
        auto change = [&](int x, int y) {
            string num_s = to_string(num);
            for (char& digit: num_s) {
                if (digit - '0' == x) {
                    digit = '0' + y;
                }
            }
            return num_s;
        };

        int min_num = num;
        int max_num = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string res = change(x, y);
                // 判断是否有前导零
                if (res[0] != '0') {
                    int res_i = stoi(res);
                    min_num = min(min_num, res_i);
                    max_num = max(max_num, res_i);
                }
            }
        }

        return max_num - min_num;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char x, char y) {
            for (char& digit: s) {
                if (digit == x) {
                    digit = y;
                }
            }
        };

        string min_num = to_string(num);
        string max_num = to_string(num);
        // 找到一个高位替换成 9
        for (char digit: max_num) {
            if (digit != '9') {
                replace(max_num, digit, '9');
                break;
            }
        }

        // 将最高位替换成 1
        // 或者找到一个与最高位不相等的高位替换成 0
        for (int i = 0; i < min_num.size(); ++i) {
            char digit = min_num[i];
            if (i == 0) {
                if (digit != '1') {
                    replace(min_num, digit, '1');
                    break;
                }
            }
            else {
                if (digit != '0' && digit != min_num[0]) {
                    replace(min_num, digit, '0');
                    break;
                }
            }
        }

        return stoi(max_num) - stoi(min_num);
    }
};

