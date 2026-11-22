/* Original Solution 1 */
class Solution {
public:
    bool checkString(string s) {
        int len = s.length();

        for (int i = 1; i < len; i++) {
            if (s[i - 1] > s[i]) {
                return false;
            }
        }

        return true;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool checkString(string s) {
        return !s.contains("ba");
    }
};

