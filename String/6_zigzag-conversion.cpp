class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();

        if (numRows == 1 || numRows >= len) {
            return s;
        }

        string ans(len, s[0]);
        int index = 0;

        while (index < len) {
            for (int row = 0; row < numRows; row++) {
                for (int col = row; col < len;) {
                    ans[index++] = s[col];
                    col += 2 * (numRows - 1);
                    if (row > 0 && row < numRows -1) {
                        if (col - 2 * row < len) {
                            ans[index++] = s[col - 2 * row];
                        }
                    }
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        int t = r * 2 - 2;
        int c = (n + t - 1) / t * (r - 1);
        vector<string> mat(r, string(c, 0));
        for (int i = 0, x = 0, y = 0; i < n; ++i) {
            mat[x][y] = s[i];
            if (i % t < r - 1) {
                ++x; // 向下移动
            } else {
                --x;
                ++y; // 向右上移动
            }
        }
        string ans;
        for (auto &row : mat) {
            for (char ch : row) {
                if (ch) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        vector<string> mat(r);
        for (int i = 0, x = 0, t = r * 2 - 2; i < n; ++i) {
            mat[x] += s[i];
            i % t < r - 1 ? ++x : --x;
        }
        string ans;
        for (auto &row : mat) {
            ans += row;
        }
        return ans;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        string ans;
        int t = r * 2 - 2;
        for (int i = 0; i < r; ++i) { // 枚举矩阵的行
            for (int j = 0; j + i < n; j += t) { // 枚举每个周期的起始下标
                ans += s[j + i]; // 当前周期的第一个字符
                if (0 < i && i < r - 1 && j + t - i < n) {
                    ans += s[j + t - i]; // 当前周期的第二个字符
                }
            }
        }
        return ans;
    }
};
