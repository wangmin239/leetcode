int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); // -1 表示该格子尚未被访问过
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.emplace(i, j); // 将所有水域入队
                }
            }
        }
        while (!q.empty()) {
            auto &p = q.front();
            for (auto &dir : dirs) {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (0 <= x && x < m && 0 <= y && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }s
            q.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9+7));
        for(int i=0; i<n; i++) {            //从左上开始遍历
            for(int j=0; j<m; j++) {
                if(isWater[i][j]) dp[i][j] = 0;
                else {
                    if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        for(int i=n-1; i>=0; i--) {         //从右下开始遍历
            for(int j=m-1; j>=0; j--) {
                if(isWater[i][j]) dp[i][j] = 0;
                else {
                    if(i < n-1) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                    if(j < m-1) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                }
            }
        }
        return dp;
    }
};
