class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        unique_ptr<int> ptr(new int [rows]);
        
        for (int cnt = 0; cnt < k; cnt++) {
            int* pArr = ptr.get();
            
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