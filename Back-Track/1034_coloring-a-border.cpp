typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pii> borders;
        int originalColor = grid[row][col];
        visited[row][col] = true;
        dfs(grid, row, col, visited, borders, originalColor);
        for (auto & [x, y] : borders) {
            grid[x][y] = color;
        }
        return grid;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>> & visited, vector<pii> & borders, int originalColor) {
        int m = grid.size(), n = grid[0].size();
        bool isBorder = false;
        int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int nx = direc[i][0] + x, ny = direc[i][1] + y;
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor)) {
                isBorder = true;
            } else if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(grid, nx, ny, visited, borders, originalColor);
            }                
        }
        if (isBorder) {
            borders.emplace_back(x, y);
        }
    }
};

typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pii> borders;
        int originalColor = grid[row][col];
        int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pii> q;
        q.emplace(row, col);
        visited[row][col] = true;
        while (!q.empty()) {
            pii & node = q.front();
            q.pop();
            int x = node.first, y = node.second;

            bool isBorder = false;
            for (int i = 0; i < 4; i++) {
                int nx = direc[i][0] + x, ny = direc[i][1] + y;
                if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor)) {
                    isBorder = true;
                } else if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }         
            }
            if (isBorder) {
                borders.emplace_back(x, y);
            }
        }
        for (auto & [x, y] : borders) {
            grid[x][y] = color;
        }
        return grid;
    }
};


class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        rows = grid.size();
        cols = grid.front().size();
        vector<vector<int>> ans(grid);
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[row][col] = true;
        backTrace(grid, ans, row, col, color, visited);
        return ans;
    }
    
    void backTrace(vector<vector<int>>& grid, vector<vector<int>>& ans, int row, int col, int color, vector<vector<bool>>& visited) {
        int adjacent[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        for (int i = 0; i < 4; i++) {
            int x = row + adjacent[i][0];
            int y = col + adjacent[i][1];
           
                       
            if ((x < rows) && (x >= 0) &&  (y < cols)  && (y >= 0) && (visited[x][y] == false) &&((grid[row][col] == grid[x][y]) || (x == 0 || x == rows -1 || y == 0 || y == cols -1))) {
                visited[x][y] = true;
                ans[x][y] = color;
                backTrace(grid, ans, x, y, color, visited);
                visited[x][y] = false;
            }
        }
    }
private:
    int rows;
    int cols;
};