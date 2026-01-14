class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
            if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j]) {
                high = i - 1;
                continue;
            }
            if (i + 1 < m && mat[i][j] < mat[i + 1][j]) {
                low = i + 1;
                continue;
            }
            return {i, j};
        }
        return {}; // impossible
    }
};



class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat.front().size();
        vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int col = max_element(mat.front().begin(), mat.front().end()) - mat.front().begin();
        
        int x = 0;
        int y = col;
        
        for (int row = 0; row < rows; row++) {
            for (auto& dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) {
                    continue;
                }
                if (mat[nx][ny] > mat[x][y]) {
                    x = nx;
                    y = ny;
                    break;
                }
            }
            
        }
        return {x, y};
    }
};