class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
    }
};



class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (hasSamePoint(points) == true) {
            return false;
        }
        
        int x0 = points[0].front();
        int y0 = points[0].back();
        
        int x1 = points[1].front();
        int y1 = points[1].back();
        
        int x2 = points[2].front();
        int y2 = points[2].back();
        
        return (y1 - y0(x2 - x0) != (y2 - y0)(x1 - x0);

    }
    
    inline bool isSame(vector<int>& point1, vector<int>& point2) {
        if (point1.front() == point2.front() &&
            point1.back() == point2.back()) {
                return true;
        }
         
        return false;
    }
    
    inline bool hasSamePoint(vector<vector<int>>& points) {
        for (int i = 1; i < points.size(); i++) {
            if (isSame(points[i - 1], points[i]) == true) {
                return true;
            }
        }
        
        return isSame(points.front(), points.back());
        
    }
};