class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xyArea = 0;
        int xzArea = 0;
        int yzArea = 0;
        int len = grid.size();
        vector<int> yzMax(len, 0);
        
        for (const auto& vec : grid) {
            int xzMax = 0;
            int i = 0;
            for (const int& val : vec) {
                xyArea += val == 0 ? 0 : 1;
                xzMax = max(xzMax, val);
                yzMax[i] = max(yzMax[i], val);
                i++;
            }
            xzArea += xzMax;
        }
        
        return xyArea + xzArea + accumulate(yzMax.begin(), yzMax.end(), 0);
    }
};


class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for (int i = 0; i < n; i++) {
            int yzHeight = 0, zxHeight = 0;
            for (int j = 0; j < n; j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = max(yzHeight, grid[i][j]);
                zxHeight = max(zxHeight, grid[j][i]);
            }
            yzArea += yzHeight;
            zxArea += zxHeight;
        }
        return xyArea + yzArea + zxArea;
    }
};
