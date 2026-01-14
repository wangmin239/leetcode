/* Oringinal Solution 1 */
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        using pii = pair<int, int>;
        auto calcTriangleArea = [](pii&& p1, pii&& p2, pii&& p3) {
            return 0.5 * abs((p2.first - p1.first) * (p3.second - p1.second)
                            - (p3.first - p1.first) * (p2.second - p1.second));
        };

        int len = points.size();
        double maxArea = 0.0;

        for (size_t i = 0; i < len - 2; i++) {
            for (size_t j = i + 1; j < len - 1; j++) {
                for (size_t k = j + 1; k < len; k++) {
                    double curArea = calcTriangleArea({points[i].front(), points[i].back()},
                                        {points[j].front(), points[j].back()},
                                        {points[k].front(), points[k].back()});
                    maxArea = max(maxArea, curArea);
                }
            }
        }

        return maxArea;
    }
};

/* Official Solution 1 */
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


/* Official Solution 2 */
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

