class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> rows, cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};










class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        int cols = grid.front().size();
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }
                int connect = 0;
                for (int i = 0; i < cols; i++) {
                    if (grid[row][i] == 1) {
                        ++connect;
                    }
                }
                
                for (int i = 0; i < rows; i++) {
                    if (grid[i][col] == 1) {
                        ++connect;
                    }
                }
                
                if (connect > 2) {
                    ++cnt;
                }
            }
        } 
        return cnt;
    }
};