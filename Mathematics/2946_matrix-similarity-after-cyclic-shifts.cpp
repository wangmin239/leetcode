/* Original Solution 1 */
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat.front().size();
        typedef enum {
            left = 0,
            right = 1,
            max
        } Directions;

        auto shift = [&](int i, int j, Directions toward) {
            int index;

            if (toward == right) {
                index = (j + k) % cols;
            } else {
                index = (j + cols - k % cols) % cols;
            }
            return mat[i][j] == mat[i][index];
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rows & 0x1) {
                    if (shift(i, j, left) != true) {
                        return false;
                    }
                } else {
                    if (shift(i, j, right) != true) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


/* Official Solution  1*/
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        for (auto& row : mat) {
            for (int j = 0; j < n; j++) {
                if (row[j] != row[(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
