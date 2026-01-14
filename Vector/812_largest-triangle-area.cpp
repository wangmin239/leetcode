class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        auto cmpX = [](const auto & lhs, const auto& rhs) {
            return lhs.front() < rhs.front();
        };

        auto cmpY = [](const auto& lhs, const auto& rhs) {
            return lhs.back() < rhs.back();
        };

        auto iter = max_element(points.begin(), points.end(), cmpX);
        auto xMaxPoint = *iter;
        
        points.erase(iter);
        iter = min_element(points.begin(), points.end(), cmpX);
        auto xMinPoint = *iter;
        points.erase(iter);

        auto yMaxPoint = *max_element(points.begin(), points.end(), cmpY);
        auto yMinPoint = *min_element(points.begin(), points.end(), cmpY);
        
        if (xMaxPoint.back() == xMinPoint.back()) {
            int len = xMaxPoint.front() - xMinPoint.front();
            int height = max(abs(yMaxPoint.back() - xMaxPoint.back()), abs(yMinPoint.back() - xMaxPoint.back()));
            return 0.5 * len * height;
        }

        double len = pow(xMaxPoint.front() - xMinPoint.front(), 2) + pow(xMaxPoint.back() - xMinPoint.back(), 2);
        

        double k = static_cast<double>((xMaxPoint.back() - xMinPoint.back())) / (xMaxPoint.front() - xMinPoint.front());
        
        double x = ( k * yMaxPoint.back() +yMaxPoint.front()  + k * k * xMaxPoint.front() - k* xMaxPoint.back())/(k*k + 1);
        double y = k*(x - xMaxPoint.front()) + xMaxPoint.back();
        
        double height = pow(yMaxPoint.front() - x, 2) + pow(yMaxPoint.back() - y, 2);
        
        double x1 = (yMinPoint.front() + k * yMinPoint.back() + k * k * xMaxPoint.front() - k* xMaxPoint.back())/(k*k + 1);
        double y1 = k*(x1 - xMaxPoint.front()) + xMaxPoint.back();        
        double height1 = pow(yMinPoint.front() - x1, 2) + pow(yMinPoint.back() - y1, 2);

        len = pow(len, 0.5);
        height = max(height, height1);
        height = pow(height, 0.5);
        return  0.5 * height * len;
        


    }
};




class Solution {
private:
    int cross(const vector<int> & p, const vector<int> & q, const vector<int> & r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> getConvexHull(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) {
            return points;
        }
        /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
        sort(points.begin(), points.end(), [](const vector<int> & a, const vector<int> & b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> hull;
        /* 求出凸包的下半部分 */
        for (int i = 0; i < n; i++) {
            while (hull.size() > 1 && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        int m = hull.size();
        /* 求出凸包的上半部分 */
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > m && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
        hull.pop_back();
        return hull;
    }

    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

public:
    double largestTriangleArea(vector<vector<int>> & points) {
        auto convexHull = getConvexHull(points);
        int n = convexHull.size();
        double ret = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = i + 2; j + 1 < n; j++) {
                while (k + 1 < n) {
                    double curArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                    double nextArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k + 1][0], convexHull[k + 1][1]);
                    if (curArea >= nextArea) {
                        break;
                    }
                    k++;
                }
                double area = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                ret = max(ret, area);
            }
        }
        return ret;
    }
};


class Solution {
public:
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

    double largestTriangleArea(vector<vector<int>> & points) {
        int n = points.size();
        double ret = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ret = max(ret, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
        }
        return ret;
    }
};
