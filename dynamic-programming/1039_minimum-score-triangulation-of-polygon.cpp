/* Official Solution 1 */
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector memo(n, vector<int>(n, -1)); // -1 表示没有计算过

        // lambda 递归函数
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i + 1 == j) {
                return 0; // 只有两个点，无法组成三角形
            }
            int& res = memo[i][j]; // 注意这里是引用，修改 res 相当于修改 memo[i][j]
            if (res != -1) { // 之前计算过
                return res;
            }
            res = INT_MAX;
            for (int k = i + 1; k < j; k++) { // 枚举顶点 k
                res = min(res, dfs(i, k) + dfs(k, j) + v[i] * v[j] * v[k]);
            }
            return res;
        };

        return dfs(0, n - 1);
    }
};

/* Official Solution 3 */
class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector f(n, vector<int>(n));
        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                f[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + v[i] * v[j] * v[k]);
                }
            }
        }
        return f[0][n - 1];
    }
};
