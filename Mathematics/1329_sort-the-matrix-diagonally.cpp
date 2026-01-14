class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diag(m + n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diag[i - j + m].push_back(mat[i][j]);
            }
        }
        for (auto& d : diag) {
            sort(d.rbegin(), d.rend());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = diag[i - j + m].back();
                diag[i - j + m].pop_back();
            }
        }
        return mat;
    }
};




class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat.front().size();
        vector<vector<int>> ans(rows, vector<int>(columns));
        
        /* upper triangle */
        for (int col = 0; col < columns; col++) {
            vector<int> diag;
            for (int row = 0; row < rows && col + row < columns; row++) {
                diag.push_back(mat[row][col + row]);
            }
            
            sort(diag.begin(), diag.end());
            int i = 0;
            for (int row = 0; row < rows && col + row < columns; row++) {
                ans[row][col + row] = diag[i++];
            }
        }
        
        /* bottom triangle */      
        for (int row = 1; row < rows; row++) {
            vector<int> diag;
            for (int col = 0; col < columns && col + row < rows; col++) {
                diag.push_back(mat[row + col][col]);
            }
            sort(diag.begin(), diag.end());
            int i = 0;
            
            for (int col = 0; col < columns && col + row < rows; col++) {
                ans[row + col][col] = diag[i++];
            }
        }
        
        return ans;
    }
};