class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};




class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        
        unique_ptr<int[]> prows(new int [rows]);
        unique_ptr<int[]> pcols(new int [cols]);
        
        auto pRowIndex = prows.get();
        auto pColIndex = pcols.get();
   

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    pRowIndex[i] = 1;
                    break;
                }
            }  
            
        }
        
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == 0) {
                    pColIndex[j] = 1;
                    break;
                }
            }  
            
        }

        for (int i = 0; i < rows; i++) {
          if (pRowIndex[i] == 1) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
          }
        }
        
        
        for (int j = 0; j < cols; j++) {
            if (pColIndex[j] == 1) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }    
        return;
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        
        unique_ptr<int[]> prows(new int [rows]);
        unique_ptr<int[]> pcols(new int [cols]);
        
        int* pRowIndex = prows.get();
        int* pColIndex = pcols.get();
        
        for (int i = 0; i < rows; i++) {
            pRowIndex[i] = 1;
        }
        
        for (int j = 0; j < cols; j++) {
            pColIndex[j] = 1;
        }
   

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    pRowIndex[i] = 0;
                    break;
                }
            }  
            
        }
        
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == 0) {
                    pColIndex[j] = 0;
                    break;
                }
            }  
            
        }

        for (int i = 0; i < rows; i++) {
          if (pRowIndex[i] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
          }
        }
        
        
        for (int j = 0; j < cols; j++) {
            if (pColIndex[j] == 0) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }    
        return;
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();
        
        //unique_ptr<int> prows(new int [rows]);
        //unique_ptr<int> pcols(new int [cols]);
        
        int* pRowIndex = new int [rows];
        int* pColIndex = new int [cols];
        
        for (int i = 0; i < rows; i++) {
            pRowIndex[i] = 1;
        }
        
        for (int j = 0; j < cols; j++) {
            pColIndex[j] = 1;
        }
   

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    pRowIndex[i] = 0;
                    break;
                }
            }  
            
        }
        
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == 0) {
                    pColIndex[j] = 0;
                    break;
                }
            }  
            
        }

        for (int i = 0; i < rows; i++) {
          if (pRowIndex[i] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
          }
        }
        
        
        for (int j = 0; j < cols; j++) {
            if (pColIndex[j] == 0) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }    
        delete [] pRowIndex;
        delete [] pColIndex;
    }
};