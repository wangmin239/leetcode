/* Original Solution 1 */
class Solution {
public:
    int minInsertions(string s) {
        int leftParenthese = 0;
        int rightParenthese = 0;
        int cnt = 0;
        const int multple = 2;

        auto getInsertCnt = [multple](int leftParenthese, int rightParenthese) {

            int doubleLeftParenthese = multple * leftParenthese;
            int cnt = 0;

            if (doubleLeftParenthese > rightParenthese) {
                return doubleLeftParenthese - rightParenthese;
            }

            int needLeftParenthese = (rightParenthese - doubleLeftParenthese + 1) / multple;
            int needRightParenthese = rightParenthese % multple;

            return needLeftParenthese + needRightParenthese;
        };


        for (char ch : s) {
            if (ch == ')') {
                ++rightParenthese;
                continue;
            }          

            cnt += rightParenthese % multple;

            if (leftParenthese * multple <= rightParenthese) {
                cnt += (rightParenthese + multple - 1) / multple - leftParenthese;
            }

            leftParenthese = max(leftParenthese - (rightParenthese + multple - 1) / multple, 0);
            rightParenthese = 0;
            ++leftParenthese;

        }

        return cnt + getInsertCnt(leftParenthese, rightParenthese);
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int leftCount = 0;
        int length = s.size();
        int index = 0;
        while (index < length) {
            char c = s[index];
            if (c == '(') {
                leftCount++;
                index++;
            } else {
                if (leftCount > 0) {
                    leftCount--;
                } else {
                    insertions++;
                }
                if (index < length - 1 && s[index + 1] == ')') {
                    index += 2;
                } else {
                    insertions++;
                    index++;
                }
            }
        }
        insertions += leftCount * 2;
        return insertions;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int left = 0; // 未配对的左括号个数
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++; // 未配对的左括号
                continue;
            }

            if (left > 0) {
                left--; // 左右括号配对
            } else {
                ans++; // 右括号太多了，补一个左括号
            }

            // 必须有两个连续的右括号，也就是 s[i+1] 必须也是右括号
            if (i < n - 1 && s[i + 1] == ')') {
                i++;
            } else {
                ans++; // 补一个右括号
            }
        }

        // 左括号太多了，补上缺失的右括号
        return ans + left * 2;
    }
};
