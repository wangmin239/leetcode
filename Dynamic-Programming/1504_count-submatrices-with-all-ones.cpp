/* Official Solution 1 */
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        vector<vector<int>> row(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
                }
                int cur = row[i][j];
                for (int k = i; k >= 0; --k) {
                    cur = min(cur, row[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int> heights(n, 0);
        int res = 0;
        for (const auto& row : mat) {
            for (int i = 0; i < n; ++i) {
                heights[i] = (row[i] == 0) ? 0 : heights[i] + 1;
            }
            stack<vector<int>> st;
            st.push({-1, 0, -1});
            for (int i = 0; i < n; ++i) {
                int h = heights[i];
                while (st.top()[2] >= h) {
                    st.pop();
                }
                auto& top = st.top();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                st.push({i, cur, h});
                res += cur;
            }
        }
        return res;
    }
};
