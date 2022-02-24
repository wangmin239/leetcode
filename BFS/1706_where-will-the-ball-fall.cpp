class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int cols = grid.front().size();
        vector<int> ans(cols, 0);
        
        for (int index = 0; index < cols; index++) {
            pair<int, int> startPoint(0, index);
            getOuter(index, startPoint, grid, ans);
        }
        
        return ans;
    }
    
    void getOuter(const int index, pair<int, int>& startPoint, vector<vector<int>>& grid, vector<int>& ans) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        auto [row, col] = startPoint;
        if (row == rows) {
            ans[index] = col;
            return;
        }
        
        if ((grid[row][col] == 1 && col == cols - 1)
            || (grid[row][col] == 1 && grid[row][col + 1] == -1)
            || (grid[row][col] == -1 && col == 0)
            || (grid[row][col] == -1 && grid[row][col - 1] == 1)){
            ans[index] = -1;
            return;
        }
        
        if (grid[row][col] == 1) {
            startPoint.first += 1;
            startPoint.second += 1;
            getOuter(index, startPoint, grid, ans);
            return;
        }
        
        if (grid[row][col] == -1) {
            startPoint.first += 1;
            startPoint.second -= 1;
            getOuter(index, startPoint, grid, ans);
        }
    }
};


class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int n = grid[0].size();
        vector<int> ans(n, -1);
        for (int j = 0; j < n; ++j) {
            int col = j; // 球的初始列
            for (auto &row : grid) {
                int dir = row[col];
                col += dir; // 移动球
                if (col < 0 || col == n || row[col] != dir) { // 到达侧边或 V 形
                    col = -1;
                    break;
                }
            }
            if (col >= 0) {  // 成功到达底部
                ans[j] = col;
            }
        }
        return ans;
    }
};
