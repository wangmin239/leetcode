/* Official Solution 1 */
class Solution {
public:
    vector<int> seg;
    void update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, p << 1 | 1, mid + 1, r);
        }
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int query(int L, int R, int p, int l, int r) {
        if (L <= l && r <= R) {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = max(res, query(L, R, p << 1 | 1, mid + 1, r));
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;
        seg.resize(mx << 2);
        set<int> st = {0, mx};
        update(mx, mx, 1, 0, mx);
        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = st.upper_bound(x);
                int r = *it;
                int l = *prev(it);
                update(x, x - l, 1, 0, mx);
                update(r, r - x, 1, 0, mx);
                st.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(0, pre, 1, 0, mx);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> bt;

    void update(int x, int v) {
        for (; x < bt.size(); x += x & -x) {
            bt[x] = max(bt[x], v);
        }
    }

    int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = max(res, bt[x]);
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;

        set<int> st = {0, mx};

        for (auto& q : queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            }
        }

        bt.resize(mx + 1);

        int pre = 0;

        for (int x : st) {
            if (x == 0) {
                continue;
            }
            update(x, x - pre);
            pre = x;
        }

        reverse(queries.begin(), queries.end());
        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(pre);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            } else {
                int x = q[1];
                auto it = st.find(x);
                int pre = *prev(it);
                int nxt = *next(it);
                update(nxt, nxt - pre);
                st.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};



/* Official Solution 3 */
class UnionFind {
public:
    vector<int> fa;

    UnionFind(int size) : fa(size) {
        for (int i = 1; i < size; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
};

class Solution {
    vector<int> t;

    void update(int i, int val) {
        for (; i < t.size(); i += i & -i) {
            t[i] = max(t[i], val);
        }
    }

    int pre_max(int i) {
        int res = 0;
        for (; i; i &= i - 1) {
            res = max(res, t[i]);
        }
        return res;
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int m = 0;
        vector<int> pos = {0};
        for (auto& q : queries) {
            m = max(m, q[1]);
            if (q[0] == 1) {
                pos.push_back(q[1]);
            }
        }
        m++;
        ranges::sort(pos);

        UnionFind left(m + 1);
        UnionFind right(m + 1);
        t.resize(m);
        for (int i = 1; i < pos.size(); i++) {
            int p = pos[i - 1];
            int q = pos[i];
            update(q, q - p);
            for (int j = p + 1; j < q; j++) {
                left.fa[j] = p; // 删除 j
                right.fa[j] = q;
            }
        }
        for (int j = pos.back() + 1; j < m; j++) {
            left.fa[j] = pos.back(); // 删除 j
            right.fa[j] = m;
        }

        vector<bool> ans;
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto& q = queries[i];
            int x = q[1];
            int pre = left.find(x - 1); // x 左侧最近障碍物的位置
            if (q[0] == 1) {
                left.fa[x] = x - 1; // 删除 x
                right.fa[x] = x + 1;
                int nxt = right.find(x); // x 右侧最近障碍物的位置
                update(nxt, nxt - pre); // 更新 d[nxt] = nxt - pre
            } else {
                // 最大长度要么是 [0,pre] 中的最大 d，要么是 [pre,x] 这一段的长度
                int max_gap = max(pre_max(pre), x - pre);
                ans.push_back(max_gap >= q[2]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
