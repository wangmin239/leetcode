/* Original Solution 1 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        constexpr int num9 = 9;
        int n = digits.size();
        int i = 0;

        while (i < n) {
            if (digits[i] != num9) {
                break;
            }
            ++i;
        }
        /* in case 1, all of the digit are number 9. */
        if (i == n) {
            fill(digits.begin(), digits.end(), 0);
            digits.insert(digits.begin(), 1);
            return digits;
        }

        constexpr int decimal = 10;
        for (int j = n - 1, incr = 1; j >= i && incr != 0; j--) {
            digits[j] += incr;
            incr = digits[j] / decimal;
            digits[j] %= decimal;
        }

        return digits;
    }
};


/* Original Solution 1 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        constexpr int num9 = 9;
        int n = digits.size();
        int i = 0;

        while (i < n) {
            if (digits[i] != num9) {
                break;
            }
            ++i;
        }
        /* in case 1, all of the digit are number 9. */
        if (i == n) {
            vector<int> ans(n + 1, 0);
            ans.front() = 1;
            return ans;
        }

        vector<int> ans(digits);
        constexpr int decimal = 10;
        for (int j = n - 1, incr = 1; j >= i && incr != 0; j--) {
            ans[j] += incr;
            incr = ans[j] / decimal;
            ans[j] %= decimal;
        }

        return ans;
    }
};