/* Official Solution 1 */
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char current = 'a';

        // 依次从 'a' 到 'z' 开始构造字符串
        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        // 验证构造的字符串是否满足 LCP 矩阵要求
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return word;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 0);
        int i = 0; // s[i] 没有填字母
        for (char c = 'a'; c <= 'z'; c++) {
            for (int j = i; j < n; j++) {
                if (lcp[i][j]) { // s[j] == s[i]
                    s[j] = c;
                }
            }
            // 找下一个空位
            while (i < n && s[i]) {
                i++;
            }
            if (i == n) { // 没有空位
                break;
            }
        }

        if (i < n) { // 还有空位
            return "";
        }

        // 验证 s 是否符合 lcp 矩阵
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // 计算后缀 [i,n-1] 和后缀 [j,n-1] 的实际 LCP
                int actual_lcp = s[i] != s[j] ? 0 : (i == n - 1 || j == n - 1 ? 1 : lcp[i + 1][j + 1] + 1);
                if (lcp[i][j] != actual_lcp) { // 矛盾
                    return "";
                }
            }
        }
        return s;
    }
};
