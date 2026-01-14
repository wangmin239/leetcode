/* Official Solution 1 */
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long tot_area = 0;
        int max_y = 0;
        for (auto& sq : squares) {
            int l = sq[2];
            tot_area += 1LL * l * l;
            max_y = max(max_y, sq[1] + l);
        }

        auto check = [&](double y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                double yi = sq[1];
                if (yi < y) {
                    double l = sq[2];
                    area += l * min(y - yi, l);
                }
            }
            return area >= tot_area / 2.0;
        };

        double left = 0, right = max_y;
        for (int i = 0; i < 47; i++) {
            double mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return (left + right) / 2; // 区间中点误差小
    }
};

/* Official Solution 2 */
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double max_y = 0, total_area = 0;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            total_area += (double)l * l;
            max_y = max(max_y, (double)(y + l));
        }
        
        auto check = [&](double limit_y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], l = sq[2];
                if (y < limit_y) {
                    area += l * min(limit_y - y, (double)l);
                }
            }
            return area >= total_area / 2;
        };
        
        double lo = 0, hi = max_y;
        double eps = 1e-5;
        while (abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};

/* Official Solution 3 */
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total_area = 0;
        vector<tuple<int, int, int>> events; 
        for (const auto& sq : squares) {
            int y = sq[1], l = sq[2];
            total_area += (long long)l * l;
            events.emplace_back(y, l, 1);
            events.emplace_back(y + l, l, -1);
        }
        // 按照 y 坐标进行排序
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });
        
        double covered_width = 0;  // 当前扫描线下所有底边之和
        double curr_area = 0;       // 当前累计面积
        double prev_height = 0;     // 前一个扫描线的高度
        for (const auto &[y, l, delta] : events) {
            int diff = y - prev_height;
            // 两条扫面线之间新增的面积
            double area = covered_width * diff;
            // 如果加上这部分面积超过总面积的一半
            if (2LL * (curr_area + area) >= total_area) {
                return prev_height + (total_area - 2.0 * curr_area) / (2.0 * covered_width);
            }
            // 更新宽度：开始事件加宽度，结束事件减宽度
            covered_width += delta * l;
            curr_area += area;
            prev_height = y;
        }
        
        return 0.0;
    }
};


/* Official Solution 4 */
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long tot_area = 0;
        map<int, long long> diff;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            tot_area += 1LL * l * l;
            diff[y] += l;
            diff[y + l] -= l;
        }

        long long area = 0, sum_l = 0;
        for (auto it = diff.begin();;) {
            auto [y, sl] = *it;
            int y2 = (++it)->first;
            sum_l += sl; // 矩形底边长度之和
            area += sum_l * (y2 - y); // 底边长 * 高 = 新增面积
            if (area * 2 >= tot_area) {
                return y2 - (area * 2 - tot_area) / (sum_l * 2.0);
            }
        }
    }
};
