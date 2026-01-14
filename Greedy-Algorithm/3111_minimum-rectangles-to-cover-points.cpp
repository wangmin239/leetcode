class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int res = 0;
        int bound = -1;
        for (auto &p : points) {
            if (p[0] > bound) {
                bound = p[0] + w;
                res++;
            }
        }
        return res;
    }
};



class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        
        sort(points.begin(), points.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.front() < rhs.front();
        });
        
        int left = points.front().front();
        int num = 1;
        
        for (int i = 0; i < n; i++) {
            if (points[i].front() > left + w) {
                left = points[i].front();
                ++num;
            }
        }
        
        return num;
    }
};