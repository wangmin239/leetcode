static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int>> heights;

    void dfs(int row, int col, vector<vector<bool>> & ocean) {
        int m = ocean.size();
        int n = ocean[0].size();
        if (ocean[row][col]) {
            return;
        }
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
                dfs(newRow, newCol, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific);
        }
        for (int j = 1; j < n; j++) {
            dfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++) {
            dfs(m - 1, j, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
    }
};

static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int>> heights;

    void bfs(int row, int col, vector<vector<bool>> & ocean) {
        if (ocean[row][col]) {
            return;
        }
        int m = heights.size();
        int n = heights[0].size();
        ocean[row][col] = true;
        queue<pair<int, int>> qu;
        qu.emplace(row, col);
        while (!qu.empty()) {
            auto [row, col] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol]) {
                    ocean[newRow][newCol] = true;
                    qu.emplace(newRow, newCol);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            bfs(i, 0, pacific);
        }
        for (int j = 1; j < n; j++) {
            bfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++) {
            bfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++) {
            bfs(m - 1, j, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights.front().size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool flowPacific = false;
                bool flowAtlantic = false;
                
                if (i == 0 || j == 0) {
                    flowPacific = true;
                }
                
                if (i == rows - 1 || j == cols - 1) {
                    flowAtlantic = true;
                }
            
                bool horizonalFlowAtlantic = true;
                for (int col = j; col < cols - 1; col++) {
                    if (heights[i][col] < heights[i][col + 1]) {
                        horizonalFlowAtlantic = false;
                        break;
                    }
                }
                
                bool verticalFlowAtlantic = true;
                for (int row = i; row < rows - 1; row++) {
                    if (heights[row][j] < heights[row + 1][j]) {
                        verticalFlowAtlantic = false;
                        break;
                    }
                }
                
                bool verticalFlowPacific = true;
                for (int row = i; row > 0; row--) {
                    if (heights[row][j] < heights[row - 1][j]) {
                            verticalFlowPacific = false;
                            break;
                    }
                }
                
                bool horizonalFlowPacific = true;
                for (int col = j; col > 0; col--) {
                    if (heights[i][col] < heights[i][col - 1]) {
                        horizonalFlowPacific = false;
                        break;
                    }
                }
                
                flowAtlantic = flowAtlantic || horizonalFlowAtlantic || verticalFlowAtlantic;
                flowPacific = flowPacific || horizonalFlowPacific || verticalFlowPacific;
                
                if (flowAtlantic == true && flowPacific == true) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
                
    }
};