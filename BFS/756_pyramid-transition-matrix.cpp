/* Original Solution 1 */
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, string> strMap;
        const int fixLen = 2;

        for (const auto& pattern : allowed) {
            string&& key = pattern.substr(0, fixLen);
            strMap[key].push_back(pattern[fixLen]);
        }

        auto dfs = [&](const string& curBottom, auto&& self) {
            int len = curBottom.length();

            if (len < fixLen) {
                return true;
            }

            vector<string> nextStr;

            for (int i = 1; i < len; i++) {
                auto&& key = curBottom.substr(i - 1, fixLen);

                if (strMap.count(key) == 0) {
                    return false;
                }
                nextStr.push_back(strMap[key]);
            }

            vector<string> prevStr {""};
            for (const string& str : nextStr) {
                vector<string> prefixStrs;
                for (char ch : str) {
                    for (string& pattern : prevStr) {
                        string nextPattern(pattern);
                        nextPattern.push_back(ch);
                        prefixStrs.push_back(nextPattern);
                    }
                }
                prevStr = move(prefixStrs);

            }


            unordered_set<string> filterStr;
            for (const string& nextBottom: prevStr) {
                if (filterStr.count(nextBottom) > 0) {
                    continue;
                }
                if (curbottom.find(nextBottom) != string::npos || self(nextBottom, self) == true) {
                    return true;
                }
                filterStr.insert(nextBottom);
            }
            return false;
        };

        return dfs(bottom, dfs);
    }
};



/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> T;
    unordered_set<long> seen;
    vector<vector<int>> A;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // 构建转换表，T[i][j] 表示底部为i和j时，顶部可能的字符位掩码
        T = vector<vector<int>>(7, vector<int>(7, 0));
        for (const string& a : allowed) {
            int left = a[0] - 'A';
            int right = a[1] - 'A';
            int top = a[2] - 'A';
            T[left][right] |= 1 << top;
        }

        seen.clear();
        int N = bottom.size();
        // 金字塔状态数组
        A = vector<vector<int>>(N, vector<int>(N, 0));
        // 初始化底部行
        for (int i = 0; i < N; i++) {
            A[N-1][i] = bottom[i] - 'A';
        }
        return solve(0, N-1, 0);
    }

    /**
     * 递归解决金字塔构建问题
     * @param R 当前行的状态编码（用于记忆化）
     * @param N 当前处理的行号
     * @param i 当前行中的位置索引
     * @return 是否可以成功构建金字塔
     */
    bool solve(long R, int N, int i) {
        // 基本情况：成功构建到金字塔顶部
        if (N == 1 && i == 1) {
            return true;
        } else if (i == N) { // 当前行处理完成，准备处理下一行
            // 记忆化检查：如果已经处理过相同的行状态，直接返回失败
            if (seen.find(R) != seen.end()) {
                return false;
            }
            // 记录当前行状态
            seen.insert(R);
            // 递归处理下一行
            return solve(0, N-1, 0);
        } else { // 处理当前行的当前位置
            // 获取当前两个底部块对应的可能顶部块位掩码
            int w = T[A[N][i]][A[N][i+1]];
            // 遍历所有可能的顶部块
            for (int b = 0; b < 7; ++b) {
                if ((w >> b) & 1) {
                    // 设置顶部块
                    A[N-1][i] = b;
                    // 递归处理下一个位置，更新状态编码
                    // 使用base-8编码来记录当前行的状态
                    if (solve(R * 8 + (b + 1), N, i + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};


/* Official Solution 2 */
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<int> groups[7][7];
        for (auto& s : allowed) {
            // A~F -> 1~6
            groups[s[0] & 31][s[1] & 31].push_back(s[2] & 31);
        }

        int n = bottom.size();
        vector<int> pyramid(n);
        for (int i = 0; i < n; i++) {
            pyramid[n - 1] |= (bottom[i] & 31) << (i * 3); // 等价于 pyramid[n-1][i] = bottom[i]&31
        }

        vector<uint8_t> vis(1 << ((n - 1) * 3));

        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0) {
                return true;
            }

            if (vis[pyramid[i]]) {
                return false;
            }

            if (j == i + 1) {
                vis[pyramid[i]] = true;
                return dfs(i - 1, 0);
            }

            for (int top : groups[pyramid[i + 1] >> (j * 3) & 7][pyramid[i + 1] >> ((j + 1) * 3) & 7]) {
                pyramid[i] &= ~(7 << (j * 3)); // 清除之前填的字母，等价于 pyramid[i][j] = 0
                pyramid[i] |= top << (j * 3); // 等价于 pyramid[i][j] = top
                if (dfs(i, j + 1)) {
                    return true;
                }
            }
            return false;
        };

        return dfs(n - 2, 0);
    }
};
