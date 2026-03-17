/* Official Solution 1 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>()); 
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, (j + 1) * matrix[i][j]); 
            }
        }
        return maxArea;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;

        for (auto& row : matrix) { // 枚举子矩形的底边
            for (int j = 0; j < n; j++) {
                int x = row[j];
                if (x == 0) {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }

            auto hs = heights;
            ranges::sort(hs);
            for (int i = 0; i < n; i++) { // 把 [i,n-1] 作为子数组
                // 子数组长为 n-i，最小值为 hs[i]，对应的子矩形面积为 (n-i)*hs[i]
                ans = max(ans, (n - i) * hs[i]); 
            }
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        vector<int> idx(n); // 按照高度排序后的列号
        ranges::iota(idx, 0); // idx[i] = i
        vector<int> non_zeros(n); // 避免在循环内反复申请内存
        int ans = 0;

        for (auto& row : matrix) {
            int p = 0, q = 0;
            for (int j : idx) {
                if (row[j] == 0) {
                    heights[j] = 0;
                    idx[p++] = j; // 高度 0 排在前面
                } else {
                    heights[j]++;
                    non_zeros[q++] = j;
                }
            }

            // heights[idx[i]] 是递增的
            for (int i = p; i < n; i++) { // 高度 0 无需计算
                idx[i] = non_zeros[i - p]; // 把 non_zeros 复制到 idx 的 [p,n-1] 中
                ans = max(ans, (n - i) * heights[idx[i]]);
            }
        }

        return ans;
    }
};
