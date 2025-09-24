/* Original Solution 1 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> existedMod;
        string  fractStr;
        constexpr int decimal = 10;

        if (numerator == 0) {
            return "0";
        }

        /* Check if the numerator is negative. */
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            fractStr.push_back('-');
        }

        unsigned long long numPos = abs(1LL * numerator);
        unsigned long long denomPos = abs(1LL * denominator);
        unsigned long long integer = numPos / denomPos;
        unsigned long long remain = numPos % denomPos;

        fractStr.append(to_string(integer));
        if (remain == 0) {
            return fractStr;
        }


        function<string(unsigned long long, unsigned long long)> dfs = [&](unsigned long long numerator, unsigned long long denominator) {
            unsigned long long  mod = numerator % denominator;
            unsigned long long  divide = numerator / denominator;

            fractStr.push_back('0' + divide);
            if (mod == 0) {
                return fractStr;
            }

            /* the fractional part is repeating */
            if (existedMod.count(mod) != 0) {
                size_t pos = existedMod[mod];
                fractStr.insert(pos, 1, '(');
                fractStr.push_back(')');
                return fractStr;
            }

            existedMod[mod] = fractStr.length();


            return dfs(mod * decimal, denominator);
        };

        fractStr.push_back('.');
        existedMod[remain] = fractStr.length();

        return dfs(remain * decimal, denomPos);
    }
};


/* Official Solution 1 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        if (numeratorLong % denominatorLong == 0) {
            return to_string(numeratorLong / denominatorLong);
        }

        string ans;
        if (numeratorLong < 0 ^ denominatorLong < 0) {
            ans.push_back('-');
        }

        // 整数部分
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long integerPart = numeratorLong / denominatorLong;
        ans += to_string(integerPart);
        ans.push_back('.');

        // 小数部分
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            index++;
        }
        if (remainder != 0) { // 有循环节
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0,insertIndex) + '(' + fractionPart.substr(insertIndex);
            fractionPart.push_back(')');
        }
        ans += fractionPart;

        return ans;
    }
};
