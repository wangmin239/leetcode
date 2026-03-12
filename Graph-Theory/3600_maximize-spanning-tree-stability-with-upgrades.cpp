/* Official Solution 1 */
struct Edge {
    int u, v, w, type;
};

class DSU {
  public:
    vector<int> parent;

    DSU(const vector<int> &p) : parent(p) {}

    int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

const int MAX_STABILITY = 2e5;

class Solution {
  public:
    int maxStability(int n, vector<vector<int>> &edges, int k) {
        int ans = -1;

        if (edges.size() < n - 1) {
            return -1;
        }

        vector<Edge> sortedEdges;
        sortedEdges.reserve(edges.size());
        for (const auto &edge : edges) {
            sortedEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
        }

        vector<Edge> mustEdges;
        vector<Edge> optionalEdges;

        for (const auto &edge : sortedEdges) {
            if (edge.type == 1) {
                mustEdges.push_back(edge);
            } else {
                optionalEdges.push_back(edge);
            }
        }

        if (mustEdges.size() > n - 1) {
            return -1;
        }
        sort(optionalEdges.begin(), optionalEdges.end(), [](const Edge &a, const Edge &b) { return b.w < a.w; });

        int selectedInit = 0;
        int mustMinStability = MAX_STABILITY;
        vector<int> initialParent(n);
        iota(initialParent.begin(), initialParent.end(), 0);
        DSU dsuInit(initialParent);

        for (const auto &edge : mustEdges) {
            if (dsuInit.find(edge.u) == dsuInit.find(edge.v) || selectedInit == n - 1) {
                return -1;
            }

            dsuInit.join(edge.u, edge.v);
            selectedInit++;
            mustMinStability = std::min(mustMinStability, edge.w);
        }

        int l = 0;
        int r = mustMinStability;

        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);

            DSU dsu(dsuInit.parent);

            int selected = selectedInit;
            int doubledCount = 0;

            for (const auto &edge : optionalEdges) {
                if (dsu.find(edge.u) == dsu.find(edge.v)) {
                    continue;
                }

                if (edge.w >= mid) {
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else if (doubledCount < k && edge.w * 2 >= mid) {
                    doubledCount++;
                    dsu.join(edge.u, edge.v);
                    selected++;
                } else {
                    break;
                }

                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid;
            }
        }

        return ans;
    }
};


/* Official Solution 2 */
class UnionFind {
    vector<int> fa; // 代表元

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), cc(n) {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己
        ranges::iota(fa, 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x) {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x) {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) { // from 和 to 在同一个集合，不做合并
            return false;
        }
        fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        cc--; // 成功合并，连通块个数减一
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind must_uf(n); // 必选边并查集
        UnionFind all_uf(n); // 全图并查集
        int min_s = INT_MAX, max_s = 0;
        for (auto& e : edges) {
            int x = e[0], y = e[1], s = e[2], must = e[3];
            if (must && !must_uf.merge(x, y)) { // 必选边成环
                return -1;
            }
            all_uf.merge(x, y);
            min_s = min(min_s, s);
            max_s = max(max_s, s);
        }

        if (all_uf.cc > 1) { // 图不连通
            return -1;
        }

        auto check = [&](int low) -> bool {
            UnionFind u(n);
            for (auto& e : edges) {
                int x = e[0], y = e[1], s = e[2], must = e[3];
                if (must && s < low) { // 必选边的边权太小
                    return false;
                }
                if (must || s >= low) {
                    u.merge(x, y);
                }
            }

            int left_k = k;
            for (auto& e : edges) {
                if (left_k == 0 || u.cc == 1) {
                    break;
                }
                int x = e[0], y = e[1], s = e[2], must = e[3];
                if (!must && s < low && s * 2 >= low && u.merge(x, y)) {
                    left_k--;
                }
            }
            return u.cc == 1;
        };

        int left = min_s, right = max_s * 2 + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};


/* Official Solution 3 */
class UnionFind {
    vector<int> fa; // 代表元

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), cc(n) {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己
        ranges::iota(fa, 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x) {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x) {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) { // from 和 to 在同一个集合，不做合并
            return false;
        }
        fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        cc--; // 成功合并，连通块个数减一
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind uf(n);
        UnionFind all_uf(n);
        int min_s1 = INT_MAX;
        for (auto& e : edges) {
            int x = e[0], y = e[1], s = e[2], must = e[3];
            if (must) {
                if (!uf.merge(x, y)) { // 必选边成环
                    return -1;
                }
                min_s1 = min(min_s1, s);
            }
            all_uf.merge(x, y);
        }

        if (all_uf.cc > 1) { // 图不连通
            return -1;
        }

        if (uf.cc == 1) { // 只需选必选边
            return min_s1;
        }

        // Kruskal 求最大生成树
        ranges::sort(edges, {}, [](auto& e) { return -e[2]; });
        vector<int> a;
        for (auto& e : edges) {
            int x = e[0], y = e[1], s = e[2], must = e[3];
            if (!must && uf.merge(x, y)) {
                a.push_back(s);
            }
        }

        // 答案为如下三者的最小值：
        // 1. must = 1 中的最小边权
        // 2. a 中最小边权 * 2
        // 3. a 中第 k+1 小边权
        int m = a.size();
        int ans = min(min_s1, a[m - 1] * 2);
        if (k < m) {
            ans = min(ans, a[m - 1 - k]);
        }
        return ans;
    }
};
