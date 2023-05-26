class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return -1;
        }
        
        int n = grid.size();
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        int steps = 1;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1) {
                    return steps;
                }
            
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }
                        if (grid[nx][ny] == 1) {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            ++steps;            
        }
       return -1;
    }
};


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return -1;
        }
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        continue;
                    }
                    if (grid[nx][ny] == 1 || dist[nx][ny] <= dist[x][y] + 1) {
                        continue;
                    }
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
                    
        }
       return -1;
    }
};