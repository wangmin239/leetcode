/* Original Solution 1 */
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rows = boxGrid.size();
        int cols = boxGrid.front().size();
        vector<vector<char>> matrix(cols, vector<char>(rows, '.'));
        
        for (int i = 0; i < rows; i++) {
            int stones = 0;
            
            for (int j = 0; j < cols; j++) {
                if (boxGrid[i][j] == '#') {
                    ++stones;
                }
                /* Shift the stones into the cell located to the left of the obstacle */
                if (boxGrid[i][j] == '*') {
                    int x = j;
                    int y = rows - i - 1;
                    
                    matrix[x][y] = '*';
                    while (stones) {                       
                        matrix[--x][y] = '#';
                        --stones;
                    }
                }  
            }
            int j = cols;
            while (stones) {
               matrix[--j][rows - i - 1] = '#';
               --stones;
            }
        }
        
        return matrix;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for (int i = 0; i < m; ++i) {
            deque<int> q;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    // 遇到障碍物，清空队列
                    q.clear();
                }
                else if (box[i][j] == '#') {
                    if (!q.empty()) {
                        // 如果队列不为空，石头就会下落
                        int pos = q.front();
                        q.pop_front();
                        box[i][pos] = '#';
                        box[i][j] = '.';
                        // 由于下落，石头变为空位，也需要加入队列
                        q.push_back(j);
                    }
                }
                else {
                    // 将空位加入队列
                    q.push_back(j);
                }
            }
        }

        // 将矩阵顺时针旋转 90 度放入答案
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            auto& row = boxGrid[i];
            int k = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (row[j] == '*') { // 障碍物
                    ans[j][m - 1 - i] = '*';
                    k = j - 1; // 障碍物左边最近的石头，在旋转后掉落到 j-1
                } else if (row[j] == '#') { // 石头
                    ans[k][m - 1 - i] = '#'; // 旋转后，石头掉落到 k
                    k--;
                }
            }
        }

        return ans;
    }
};
