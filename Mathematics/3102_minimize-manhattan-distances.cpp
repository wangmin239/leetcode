class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sx, sy;
        for (auto & p : points) {
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }
        int res = INT_MAX;
        for (auto &p : points) {
            sx.erase(sx.find(p[0] - p[1]));
            sy.erase(sy.find(p[0] + p[1]));
            res = min(res, max(*sx.rbegin() - *sx.begin(), *sy.rbegin() - *sy.begin()));
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }
        return res;
    }
};

class Solution {
public:
    int remove(vector<pair<int, int>> &arr, int i) {
        int n = arr.size();
        if (arr[0].second == i) {
            return arr[n - 1].first - arr[1].first;
        } else if (arr.back().second == i) {
            return arr[n - 2].first - arr[0].first;
        } else {
            return arr[n - 1].first - arr[0].first;
        }
    }
    
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> sx, sy;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            sx.emplace_back(x - y, i);
            sy.emplace_back(x + y, i);
        }
        sort(sx.begin(), sx.end());
        sort(sy.begin(), sy.end());
        int maxVal1 = sx.back().first - sx[0].first;
        int maxVal2 = sy.back().first - sy[0].first;
        int res = INT_MAX;
        if (maxVal1 >= maxVal2) {
            int i = sx[0].second, j = sx.back().second;
            // 去掉 i 后的最大曼哈顿距离
            res = min(res, max(remove(sx, i), remove(sy, i)));
            // 去掉 j 后的最大曼哈顿距离
            res = min(res, max(remove(sx, j), remove(sy, j)));
        } else {
            int i = sy[0].second, j = sy.back().second;
            // 去掉 i 后的最大曼哈顿距离
            res = min(res, max(remove(sx, i), remove(sy, i)));
            // 去掉 j 后的最大曼哈顿距离
            res = min(res, max(remove(sx, j), remove(sy, j)));
        }
        
        return res;
    }
};
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        size_t idx = 0;
        size_t n = points.size();
        auto mark = [&] (const auto f) {
            idx = 0;
            for (size_t i = 1; i < n; ++i) {
                if (f(points[i]) < f(points[idx])) {
                    idx = i;
                }
            }
        };
        auto distance = [&] () {
            int a = INT_MAX;
            int b = INT_MIN;
            int c = INT_MAX;
            int d = INT_MIN;
            for (size_t i = 0; i < n; ++i) {
                if (i == idx) {
                    continue;
                }
                const auto& point = points[i];
                int x = point[0];
                int y = point[1];
                a = min(a, x + y);
                b = max(b, x + y);
                c = min(c, x - y);
                d = max(d, x - y);
            }
            return max(b - a, d - c);
        };
        mark([] (const auto& p) {return p[0] + p[1]; });
        int d1 = distance();
        mark([] (const auto& p) {return -p[0] - p[1]; });
        int d2 = distance();
        mark([] (const auto& p) {return p[0] - p[1]; });
        int d3 = distance();
        mark([] (const auto& p) {return -p[0] + p[1]; });
        int d4 = distance();
        return min({d1, d2, d3, d4});
    }
};