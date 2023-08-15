class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = dp[i - 1][j];
                if (j > 0) {
                    mn = min(mn, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};






class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        
        for (int col = 0; col < matrix.front().size(); col++) {
            minSum = min(minSum, dfs(0, col, matrix, matrix[0][col]));
        }
        return minSum;
    }
    
    int dfs(int row, int col, vector<vector<int>>& matrix, int curSum)
    {
        if (row == matrix.size() - 1) {
            return curSum;
        }

        vector<pair<int, int>> offset {{1, -1}, {1, 0}, {1, 1}};
        
        auto isValid = [&matrix](int row, int col) {
            if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix.size()) {
                return false;
            }
            return true;
        };
        

        int minSum = INT_MAX;
        for (auto const& ele : offset) {
            int x = row + ele.first;
            int y = col + ele.second;
            if (isValid(x, y) == false) {
                continue;
            }
            
            int curVal =  dfs(x, y, matrix, curSum + matrix[x][y]);
            minSum = min(minSum, curVal);
        }
        return minSum;
    }
};