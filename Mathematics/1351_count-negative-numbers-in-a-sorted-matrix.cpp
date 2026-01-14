/* Original Solution 1 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int negCnt = 0;
        int y = cols - 1;
        
        for (int x = 0; x < rows; x++) {
            
            while (y >= 0 && grid[x][y] < 0) {
                y--;
            }
            
            if (y < 0) {
                negCnt += cols;
            } else {
                negCnt += cols - y - 1;
            }
        }

        return negCnt;
        
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int num = 0;
        for (auto x : grid) {
            int l = 0, r = (int)x.size() - 1, pos = -1;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (x[mid] < 0) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
            if (~pos) {  // pos != -1 表示这一行存在负数
                num += (int)x.size() - pos;
            }
        }
        return num;
    }
};
