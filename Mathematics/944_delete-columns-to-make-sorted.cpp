/* Original Solution 1 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs.front().length();
        unique_ptr<bool[cols]> needDel(new bool[cols]);
        auto ptr = needDel.get();
        int delCnt = 0;

        fill(ptr, ptr + cols, false);

        for (int row = 1; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (ptr[col] == true) {
                    continue;
                }

                if (strs[row - 1][col] > strs[row - 1][col]) {
                    ptr[col] = true;
                    ++delCnt;
                }
            }
        }

        return delCnt;
    }
};



/* Original Solution 2 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs.front().length();
        int delCnt = 0;


        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < rows; row++) {
                if (strs[row - 1][col] > strs[row][col]) {
                    ++delCol;
                    break;
                }
            }
        }

        return delCol;
    }
};