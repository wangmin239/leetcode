/* Original Solution 1 */
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int len = s1.length();

        for (int i = 0, j = 2;  j < len; i++, j++) {
            if (s1[i] == s2[i] && s1[j] == s2[j] ||
                s1[i] == s2[j] && s1[j] == s2[i]) {
                 continue;
            } else {
                return false;
            }

        }
        return true;
    }
};