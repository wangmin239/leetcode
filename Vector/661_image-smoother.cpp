class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = 0, sum = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            num++;
                            sum += img[x][y];
                        }
                    }
                }
                ret[i][j] = sum / num;
            }
        }
        return ret;
    }
};







class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img.front().size();
        
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int cnt = 1;
                int sum = img[row][col];
                /* upper row */
                if (row - 1 >= 0) {
                    sum += img[row - 1][col];
                    ++cnt;
                    if (col - 1 >= 0) {
                        sum += img[row - 1][col - 1];
                        ++cnt;
                    }
                    if (col + 1 < cols) {
                        sum += img[row - 1][col + 1];
                        ++cnt;
                    }
                        
                }
                /* the same row */
                if (col - 1 >= 0) {
                    sum += img[row][col - 1];
                    ++cnt;
                }
                
                if (col + 1 < cols) {
                    sum += img[row][col + 1];
                    ++cnt;
                }
                /* below row */
                if (row + 1 < rows) {
                    ++cnt;
                    sum += img[row + 1][col];
                    if (col - 1 >= 0) {
                        sum += img[row + 1][col - 1];
                        ++cnt;
                    }
                    if (col + 1 < cols) {
                        ++cnt;
                        sum += img[row + 1][col + 1];
                    }
                }
                
                ans[row][col] = floor(sum / cnt);
            }
        }
        return ans;        
    }
};