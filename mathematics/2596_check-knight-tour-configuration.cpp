class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        unique_ptr<pair<int, int>[]>  posInfo(new pair<int, int>[total]);
        
        pair<int, int> *ptr = posInfo.get();        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int id = grid[row][col];
                ptr[id] = make_pair(row, col);
            }
        }
        
        
        if (ptr[0] != make_pair(0, 0)) {
            return false;
        }
        
        auto isValid = [&ptr](int pre, int cur) {
            int preX = ptr[pre].first;
            int preY = ptr[pre].second;
            int curX = ptr[cur].first;
            int curY = ptr[cur].second;
            
            if ((abs(curX - preX) == 2 && abs(curY - preY) == 1) ||
                (abs(curX - preX) == 1 && abs(curY - preY) == 2)) {
                    return true;
            }
            return false;
        };
        
        for (int i = 1; i < n * n; i++) {
            if (isValid(i - 1, i) == false) {
                return false;
            }
        }
        
        return true;
    }
};





class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        vector<pair<int, int>>  posInfo(total);
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int id = grid[row][col];
                posInfo[id] = make_pair(row, col);
            }
        }
        
        
        if (posInfo[0] != make_pair(0, 0)) {
            return false;
        }
        
        auto isValid = [&posInfo](int pre, int cur) {
            int preX = posInfo[pre].first;
            int preY = posInfo[pre].second;
            int curX = posInfo[cur].first;
            int curY = posInfo[cur].second;
            
            if ((abs(curX - preX) == 2 && abs(curY - preY) == 1) ||
                (abs(curX - preX) == 1 && abs(curY - preY) == 2)) {
                    return true;
            }
            return false;
        };
        
        for (int i = 1; i < n * n; i++) {
            if (isValid(i - 1, i) == false) {
                return false;
            }
        }
        
        return true;
    }
};


class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        
        map<int, pair<int, int>> posInfo;
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int id = grid[row][col];
                posInfo[id] = make_pair(row, col);
            }
        }
        
        
        if (posInfo[0] != make_pair(0, 0)) {
            return false;
        }
        
        auto isValid = [&posInfo](int pre, int cur) {
            int preX = posInfo[pre].first;
            int preY = posInfo[pre].second;
            int curX = posInfo[cur].first;
            int curY = posInfo[cur].second;
            
            if ((abs(curX - preX) == 2 && abs(curY - preY) == 1) ||
                (abs(curX - preX) == 1 && abs(curY - preY) == 2)) {
                    return true;
            }
            return false;
        };
        
        for (int i = 1; i < n * n; i++) {
            if (isValid(i - 1, i) == false) {
                return false;
            }
        }
        
        return true;
    }
};




class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        vector<array<int, 2>> indices(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                indices[grid[i][j]] = {i, j};
            }
        }
        for (int i = 1; i < indices.size(); i++) {
            int dx = abs(indices[i][0] - indices[i - 1][0]);
            int dy = abs(indices[i][1] - indices[i - 1][1]);
            if (dx * dy != 2) {
                return false;
            }
        }
        return true;
    }
};
