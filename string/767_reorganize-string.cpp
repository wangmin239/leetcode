class Solution {
public:
    string reorganizeString(string S) {
        constexpr int chLen = 26;
        int chArray[chLen] = {0};
        int chMax = 0;
        /* statistic the repeated times for every character. */
        for (auto &ch : S) {
            chArray[ch - 'a']++;
            chMax = max(chArray[ch - 'a'], chMax);
        }


        int len = S.length();
        int halfLen = (len + 1) / 2;

        /* if the repeated times of a character is over the half of the string */
        if (chMax > halfLen) {
            return "";
        }

        string res(len, 0);
        int oddIndex = 1;
        int evenIndex = 0;
        halfLen = len / 2;

        for (int i = 0; i < chLen; i++) {
            if (chArray[i] == 0) {
                continue;
            }
            char ch = 'a' + i;
            /* permutation */
            while (chArray[i] > 0 && chArray[i] <= halfLen && oddIndex < len) {
                chArray[i]--;
                res[oddIndex] = ch;
                oddIndex += 2;
            }

            while (chArray[i] > 0 && evenIndex < len) {
                chArray[i]--;
                res[evenIndex] = ch;
                evenIndex += 2;
            }
        }
        return res;
    }
};
