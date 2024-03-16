class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> q, q2;
        for (int i = 0; i < m; i++) {
            q.insert(i);
        }
        for (int j = 1; j < n; j++) {
            q2.clear();
            for (int i : q) {
                for (int i2 = i - 1; i2 <= i + 1; i2++) {
                    if (0 <= i2 && i2 < m && grid[i][j - 1] < grid[i2][j]) {
                        q2.insert(i2);
                    }
                }
            }
            swap(q, q2);
            if (q.empty()) {
                return j - 1;
            }
        }
        return n - 1;
    }
};





class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        int steps = 0;
        unordered_set<int> indexSet;
        
        for (int i = 0; i < rows; i++) {
            indexSet.insert(i);
        }
        
        for (int col = 1; col < cols; col++) {

            unordered_set<int> tmpSet;
            for (int row : indexSet) {
                
                if (grid[row][col + 1] > grid[row][col]) {
                    tmpSet.insert(row);
                } 
                
                if (row > 0 && grid[row - 1][col + 1] > grid[row][col]) {
                    tmpSet.insert(row - 1);
                }
                
                if (row < rows - 1 && grid[row + 1][col + 1] > grid[row][col]) {
                    tmpSet.insert(row + 1);
                }
            }
            
            if (tmpSet.empty() == true) {
                break;
            }
            ++steps;
            indexSet = tmpSet;
        }
        
        return steps;
    }
    
};