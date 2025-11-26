/* Original Solution 1 */
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();
        auto pairHash = [](const pair<int, int>& key) {
                            return hash<int>()(key.first << 6) | hash<int>()(key.second);
        };
        
        unordered_map<pair<int, int>, int, decltype(pairHash)> posMod(1, pairHash);
        constexpr int mod = 1e9 + 7;
        function<int(int, int, int)> dfs = [&](int row, int col, int remainder) {
            int val = 0;
            
            if (row < 0 || col < 0) {
                return 0;
            }
            
            if (row == 0 && col == 0) {
                val = grid[row][col] + remainder;
                return val % k == 0 ? 1 : 0;
            }
            

            

            pair<int, int> pos = make_pair(row * n + col, remainder);
            if (posMod.count(pos) != 0) {
                return posMod[pos];
            }
            
            val = grid[row][col] + remainder;
            remainder = val % k;
            long path = 0;
            path += dfs(row - 1, col, remainder);
            path += dfs(row, col - 1, remainder);
            path %= mod;

            posMod[pos] = path;
            
            return static_cast<int>(path);
        };
        
        return dfs(m - 1, n - 1, 0) % mod ;
    }
};
                   ^
/* Official Solution 1 */
typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector(m + 1, vector(n + 1, vector<ll>(k)));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }

                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prevMod = (r - value + k) % k;
                    dp[i][j][r] =
                        (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return dp[m][n][0];
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr static int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector(n, vector<int>(k, -1))); // -1 表示没有计算过

        auto dfs = [&](this auto&& dfs, int i, int j, int s) -> int {
            if (i < 0 || j < 0) { // 出界
                return 0;
            }
            int pre_s = ((s - grid[i][j]) % k + k) % k; // 保证模 k 结果非负
            if (i == 0 && j == 0) { // 起点
                return pre_s == 0; // pre_s == 0 说明 s == grid[i][j] % k
            }
            int& res = memo[i][j][s]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            return res = (dfs(i - 1, j, pre_s) + dfs(i, j - 1, pre_s)) % MOD;
        };

        return dfs(m - 1, n - 1, 0);
    }
};

/* Official Solution 3 */
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();
        vector f(m + 1, vector(n + 1, vector<int>(k)));
        f[0][1][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int s = 0; s < k; s++) {
                    int new_s = (s + grid[i][j]) % k;
                    f[i + 1][j + 1][s] = (f[i][j + 1][new_s] + f[i + 1][j][new_s]) % MOD;
                }
            }
        }
        return f[m][n][0];
    }
};
