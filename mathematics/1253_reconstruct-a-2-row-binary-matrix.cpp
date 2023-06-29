class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int sum = 0, two = 0;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ++two;
            }
            sum += colsum[i];
        }
        if (sum != upper + lower || min(upper, lower) < two) {
            return {};
        }
        upper -= two;
        lower -= two;
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (upper > 0) {
                    res[0][i] = 1;
                    --upper;
                } else {
                    res[1][i] = 1;
                }
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int colSize = colsum.size();

        if (upper + lower != accumulate(colsum.begin(), colsum.end(), 0)) {
            return {};
        }
        vector<vector<int>> matrix(2, vector<int>(colSize, 0));
        /* check if colsum[col] is equal to 2 or 0 */
        for (int col = 0; col < colSize; col++) {
            if (colsum[col] != 1) {
                matrix[0][col] = colsum[col] / 2;
                matrix[1][col] = colsum[col] / 2;
                upper -= matrix[0][col];
                lower -= matrix[1][col];
            }
        }
        /* check if the condition is satisficed */
        if (upper < 0 || lower < 0) {
            return {};
        }
        /* replenish the elements */
        for (int col = 0; col < colSize; col++) {
            if (colsum[col] == 1) {
                if (upper != 0) {
                    matrix[0][col] = 1;
                    --upper;
                    continue;
                }
                matrix[1][col] = 1;
            }
        }
        return matrix;
    }
};






class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int colSize = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(colSize, 0));
        vector<int> oneIndex;
        
        if (upper + lower != accumulate(colsum.begin(), colsum.end(), 0)) {
            return {};
        }
        /* check if colsum[col] is equal to 2 or 0 */
        for (int col = 0; col < colSize; col++) {
            if (colsum[col] != 1) {
                matrix[0][col] = colsum[col] / 2;
                matrix[1][col] = colsum[col] / 2;
                upper -= matrix[0][col];
                lower -= matrix[1][col];
            } else {
                oneIndex.push_back(col);
            }
        }
        
        if (upper < 0 || lower < 0) {
            return {};
        }
        
        int oneLen = oneIndex.size();
        if (upper + lower != oneLen) {
            return {};
        }
        
        for (int i = 0; i < oneLen; i++) {
            int col = oneIndex[i];
            if (upper != 0) {
                matrix[0][col] = 1;
                --upper;
                continue;
            }
            matrix[1][col] = 1;
        }
        return matrix;
    }
};