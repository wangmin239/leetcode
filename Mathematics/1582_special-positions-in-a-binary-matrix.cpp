/* Original Solution 1 */
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat.front().size();
        int ans = 0;

        for (const auto& row : mat) {
            if (accumulate(row.begin(), row.end(), 0) != 1) {
                continue;
            }

            int sum = 0;
            for (int j = 0; j < cols; j++) {
                if (row[j] == 1) {
                    for (int i = 0; i < rows; i++) {
                        sum += mat[i][j];
                    }
                }
            }
            if (sum == 1) {
                ++ans;
            }
        }

        return ans;

    }
};



/* Official Solution 1 */
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int cnt1 = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    cnt1++;
                }
            }
            if (i == 0) {
                cnt1--;
            }
            if (cnt1 > 0) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1) {
                        mat[0][j] += cnt1;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mat[0][i] == 1) {
                sum++;
            }
        }
        return sum;
    }
};
