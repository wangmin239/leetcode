class Solution {
public:
    string sortString(string s) {
        int len = s.length();
        string res(len, 'a');
        int chArray[26] = { 0 };
        /* statistic every character in the string */
        for (auto &elem : s) {
            chArray[elem - 'a']++;
        }


        int index = 0;
        while (index < len) {
            /* get the mininal characters */
            for (int i = 0; i < sizeof(chArray) / sizeof(chArray[0]); i++) {
                if (chArray[i]-- > 0) {
                    res[index++] = 'a' + i; 
                }
            }
            /* get the maxnal characters */
            for (int i = sizeof(chArray) / sizeof(chArray[0])- 1; i >= 0; i--) {
                if (chArray[i]-- > 0) {
                    res[index++] = 'a' + i;
                }
            }
        }
        
        return res;
    }
};