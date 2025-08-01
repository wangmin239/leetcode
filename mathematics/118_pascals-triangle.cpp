/* Original solution 1 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        function<void(int, int)> dfs = [&ans, &dfs](int curNum, int numRows) {
            if (curNum > numRows) {
                return;
            }
            
            vector<int> curRow(curNum, 1); 
            int i = 1;
            
            for (auto iter = ans.back().begin(); iter != ans.back().end() - 1; ++iter) {
                curRow[i++] = *(iter + 1) + *iter;
            }
            
            ans.push_back(move(curRow));
            
            dfs(curNum + 1, numRows);
        };
        
        ans.push_back({1});
        dfs(2, numRows);
        
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
