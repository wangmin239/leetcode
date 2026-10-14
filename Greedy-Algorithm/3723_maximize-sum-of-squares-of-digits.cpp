/* Original Solution 1 */
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        const int decimal = 10;
        int nineCnt = sum /(decimal - 1);
        int remainDigit = sum - (decimal - 1) * nineCnt;
        int nonZeroCnt = nineCnt + static_cast<int>(remainDigit != 0);

        if (nonZeroCnt > num) {
            return "";
        }

        string digitStr(num, '0');

        for (int i = 0; i < nineCnt; i++) {
            digitStr[i] += decimal - 1;
        }

        digitStr[nineCnt] += remainDigit;

        return digitStr;
    }
};


/* Official Solution 1 */
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int r = sum % 9;
        string ans(sum / 9, '9');
        if (r > 0) {
            ans.push_back('0' + r);
        }
        ans.append(num - (int)ans.size(), '0');
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        if (n * 9 < sum) {
            return "";
        }
        string ans(sum / 9, '9');
        if (sum % 9) {
            ans += '0' + sum % 9;
        }
        return ans + string(n - ans.size(), '0');
    }
};
