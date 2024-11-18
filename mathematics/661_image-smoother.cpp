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
        vector<vector<int>> matrix(rows, vector<int>(cols));
        
        auto calAverage = [rows, cols](const int x, const int y, const vector<vector<int>>& img) ->int {
            const int size = 9;
            int adjacentPoints[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
            {1, 1}, {1, 0}, {1, -1}, {0, -1}, {0, 0}};
            
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < size; i++) {
                int row = x + adjacentPoints[i][0];
                int col = y + adjacentPoints[i][1];
                
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    sum += img[row][col];
                    ++cnt;
                }
            }
            
            return sum / cnt;
        };
        
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                matrix[x][y] = calAverage(x, y, img);
            }
        }
        
        return matrix;
    }
};