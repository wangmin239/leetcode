/* Original Solution 1 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs.front().length();
        int cnt = 0;
        vector<bool> delColIds(cols, false);

        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < rows; row++) {
                if (strs[row - 1][col] > strs[row][col]) {
                    if (delColIds[col] == true) {
                        break;
                    }


                    int i = col;
                    while (--i >= 0) {
                        if (delColIds[i] == false && strs[row - 1][i] < strs[row][i]) {
                            break;
                        }
                    }

                    if (i < 0) {
                        ++cnt;
                        delColIds[col] = true;
                    }
                }
            }
        }

        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> check_list(n - 1);
        ranges::iota(check_list, 0);

        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool del = false;
            for (int i : check_list) {
                if (strs[i][j] > strs[i + 1][j]) {
                    // j 列不是升序，必须删
                    ans++;
                    del = true;
                    break;
                }
            }
            if (del) {
                continue;
            }
            // j 列是升序，不删更好
            int new_size = 0;
            for (int i : check_list) {
                if (strs[i][j] == strs[i + 1][j]) {
                    // 相邻字母相等，下一列 i 和 i+1 需要继续比大小
                    check_list[new_size++] = i; // 原地覆盖
                }
            }
            check_list.resize(new_size);
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<string> a(n); // 最终得到的字符串数组
        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool del = false;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] + strs[i][j] > a[i + 1] + strs[i + 1][j]) {
                    // j 列不是升序，必须删
                    ans++;
                    del = true;
                    break;
                }
            }
            if (!del) {
                // j 列是升序，不删更好
                for (int i = 0; i < n; i++) {
                    a[i] += strs[i][j];
                }
            }
        }
        return ans;
    }
};
