class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        
        for (int i = 0, j = 0; i < rows && j < cols; ) {
            int val = min(rowSum[i], colSum[j]);
            rowSum[i] -= val;
            colSum[j] -= val;
            matrix[i][j] = val;            
            if (rowSum[i] == 0) {
                ++i;
            }
            
            if (colSum[j] == 0) {
                ++j;
            }

        }
        return matrix;
    }
};