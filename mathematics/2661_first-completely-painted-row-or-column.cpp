class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> matrix;
        int rows = mat.size();
        int cols = mat.front().size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[mat[i][j]] = make_pair(i, j);
            }
        }
        
        vector<int> rowsCnt(rows, cols);
        vector<int> colsCnt(cols, rows);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            int row = matrix[val].first;
            int col = matrix[val].second;
            --rowsCnt[row];
            --colsCnt[col];
            if (rowsCnt[row] == 0 ||colsCnt[col] == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCnt(n, 0);
        vector<int> colCnt(m, 0);
        for (int i = 0; i < arr.size(); ++i) {
            auto& v = mp[arr[i]];
            ++rowCnt[v.first];
            if (rowCnt[v.first] == m) {
                return i;
            }
            ++colCnt[v.second];
            if (colCnt[v.second] == n) {
                return i;
            }
        }
        return -1;
    }
};
