class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        unique_ptr<int*> ptr = make_unique<int*>(new int [rows]);
        
        for (int cnt = 0; cnt < k; cnt++) {
            int* pArr = *ptr.get();
            
            /* The last column */
            for (int row = 0, col = cols - 1; row < rows - 1; row++) {
                pArr[row + 1] = grid[row][col];
            }
            pArr[0] = grid[rows - 1][cols - 1];
            
            /* shift column */
            for (int col = cols - 2; col >= 0; col--) {
                for (int row = 0; row < rows; row++) {
                    grid[row][col + 1] = grid[row][col];
                }
            }
            
            /* The first column */
            for (int row = 0, col = 0; row < rows; row++) {
                grid[row][col] = pArr[row];
            }
        }
        
        return grid;
    }
    

};



class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index1 = (i * n + j + k) % (m * n);
                ret[index1 / n][index1 % n] = grid[i][j];
            }
        }
        return ret;
    }
};
