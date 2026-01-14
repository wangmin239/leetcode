/* Official Solution 1 */
class SegmentTree {
public:
    SegmentTree(vector<int>& xs) {
        unsigned n = xs.size() - 1; // xs.size() 个横坐标有 xs.size()-1 个差值
        seg.resize(2 << bit_width(n - 1));
        build(xs, 1, 0, n - 1);
    }

    void update(int l, int r, int v) {
        update(1, l, r, v);
    }

    int get_uncovered_length() {
        return seg[1].min_cover ? 0 : seg[1].min_cover_len;
    }

private:
    struct Node {
        int l, r;
        int min_cover_len = 0; // 区间内被矩形覆盖次数最少的底边长之和
        int min_cover = 0;     // 区间内被矩形覆盖的最小次数
        int todo = 0;          // 子树内的所有节点的 min_cover 需要增加的量，注意这可以是负数
    };

    vector<Node> seg;

    // 根据左右儿子的信息，更新当前节点的信息
    void maintain(int o) {
        Node& lo = seg[o * 2];
        Node& ro = seg[o * 2 + 1];
        int mn = min(lo.min_cover, ro.min_cover);
        seg[o].min_cover = mn;
        // 只统计等于 min_cover 的底边长之和
        seg[o].min_cover_len = (lo.min_cover == mn ? lo.min_cover_len : 0) +
                               (ro.min_cover == mn ? ro.min_cover_len : 0);
    }

    // 仅更新节点信息，不下传懒标记 todo
    void do_(int o, int v) {
        seg[o].min_cover += v;
        seg[o].todo += v;
    }

    // 下传懒标记 todo
    void spread(int o) {
        int& v = seg[o].todo;
        if (v != 0) {
            do_(o * 2, v);
            do_(o * 2 + 1, v);
            v = 0;
        }
    }

    // 建树
    void build(vector<int>& xs, int o, int l, int r) {
        seg[o].l = l;
        seg[o].r = r;
        if (l == r) {
            seg[o].min_cover_len = xs[l + 1] - xs[l];
            return;
        }
        int m = (l + r) / 2;
        build(xs, o * 2, l, m);
        build(xs, o * 2 + 1, m + 1, r);
        maintain(o);
    }

    // 区间更新
    void update(int o, int l, int r, int v) {
        if (l <= seg[o].l && seg[o].r <= r) {
            do_(o, v);
            return;
        }
        spread(o);
        int m = (seg[o].l + seg[o].r) / 2;
        if (l <= m) {
            update(o * 2, l, r, v);
        }
        if (m < r) {
            update(o * 2 + 1, l, r, v);
        }
        maintain(o);
    }
};

// 代码逻辑同 850 题，增加一个 records 数组记录关键数据
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> xs;
        struct Event { int y, lx, rx, delta; };
        vector<Event> events;
        for (auto& sq : squares) {
            int lx = sq[0], y = sq[1], l = sq[2];
            int rx = lx + l;
            xs.push_back(lx);
            xs.push_back(rx);
            events.emplace_back(y, lx, rx, 1);
            events.emplace_back(y + l, lx, rx, -1);
        }

        // 排序去重，方便离散化
        ranges::sort(xs);
        xs.erase(ranges::unique(xs).begin(), xs.end());

        // 初始化线段树
        SegmentTree t(xs);

        // 模拟扫描线从下往上移动
        ranges::sort(events, {}, &Event::y);
        vector<pair<long long, int>> records(events.size() - 1);
        long long tot_area = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            auto& [y, lx, rx, delta] = events[i];
            int l = ranges::lower_bound(xs, lx) - xs.begin(); // 离散化
            int r = ranges::lower_bound(xs, rx) - xs.begin() - 1; // r 对应着 xs[r] 与 xs[r+1]=rx 的差值
            t.update(l, r, delta); // 更新被 [lx, rx] 覆盖的次数
            int sum_len = xs.back() - xs[0] - t.get_uncovered_length(); // 减去没被矩形覆盖的长度
            records[i] = {tot_area, sum_len};
            tot_area += 1LL * sum_len * (events[i + 1].y - y); // 新增面积 = 被至少一个矩形覆盖的底边长之和 * 矩形高度
        }

        // 二分找最后一个 < tot_area / 2 的面积
        int i = ranges::lower_bound(records, tot_area, {}, [](auto& p) { return p.first * 2; }) - records.begin() - 1;
        auto [area, sum_len] = records[i];
        return events[i].y + (tot_area - area * 2) / (sum_len * 2.0);
    }
};

/* Official Solution 2 */
class SegmentTree {
private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;
    
    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }
        
        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }
    
    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }
    
    int query() {
        return covered[0];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;
        
        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }
        
        // 按y坐标排序事件
        sort(events.begin(), events.end());
        // 离散化坐标
        vector<int> xs(xsSet.begin(), xsSet.end());
        // 初始化线段树
        SegmentTree segTree(xs);
        
        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);
        
        // 扫描：计算总面积和记录中间状态
        for (auto& [y, delta, xl, xr] : events) {
            int len = segTree.query();
            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);
            // 记录前缀和和宽度
            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }
        
        // 计算目标面积（向上取整的一半）
        long long target = (long long)(total_area + 1) / 2;
        // 二分查找第一个大于等于target的位置
        int i = lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        // 获取对应的面积、宽度和高度
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
    }
};
