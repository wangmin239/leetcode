/* Original Solution 1 */
class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftParentheses = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                ++leftParentheses;
                continue;
            }

            if (leftParentheses > 0) {
                --leftParentheses;
            } else {
                ++ans;
            }
        }

        return ans + leftParentheses;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int leftCount = 0;
        for (auto &c : s) {
            if (c == '(') {
                leftCount++;
            } else {
                if (leftCount > 0) {
                    leftCount--;
                } else {
                    ans++;
                }
            }
        }
        ans += leftCount;
        return ans;
    }
};
