/* Official Solution 1 */
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end(), [&](const auto& x, const auto& y) {
            return x[2] < y[2];
        });

        vector<int> secret(n);
        secret[0] = secret[firstPerson] = true;

        unordered_set<int> vertices;
        unordered_map<int, vector<int>> edges;

        for (int i = 0; i < m;) {
            // meetings[i .. j] 为同一时间
            int j = i;
            while (j + 1 < m && meetings[j + 1][2] == meetings[i][2]) {
                ++j;
            }

            vertices.clear();
            edges.clear();
            for (int k = i; k <= j; ++k) {
                int x = meetings[k][0], y = meetings[k][1];
                vertices.insert(x);
                vertices.insert(y);
                edges[x].push_back(y);
                edges[y].push_back(x);
            }

            queue<int> q;
            for (int u: vertices) {
                if (secret[u]) {
                    q.push(u);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: edges[u]) {
                    if (!secret[v]) {
                        secret[v] = true;
                        q.push(v);
                    }
                }
            }

            i = j + 1;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (secret[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class UnionFind {
public:
    vector<int> fa; // 代表元

    UnionFind(int n) : fa(n) {
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

    // 判断 x 和 y 是否在同一个集合
    bool is_same(int x, int y) {
        // 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        // 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return find(x) == find(y);
    }

    // 把 from 所在集合合并到 to 所在集合中
    void merge(int from, int to) {
        int x = find(from), y = find(to);
        fa[x] = y; // 合并集合
    }
};



class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // 按照 time 从小到大排序
        ranges::sort(meetings, {}, [](auto& a) { return a[2]; });

        UnionFind uf(n);
        // 一开始 0 和 firstPerson 都知道秘密
        uf.merge(firstPerson, 0);

        // 分组循环
        int m = meetings.size();
        for (int i = 0; i < m;) {
            int start = i;
            int time = meetings[i][2];
            // 合并在同一时间发生的会议
            for (; i < m && meetings[i][2] == time; i++) {
                uf.merge(meetings[i][0], meetings[i][1]);
            }

            // 如果节点不和 0 在同一个集合，那么撤销合并，恢复成初始值
            for (int j = start; j < i; j++) {
                int x = meetings[j][0], y = meetings[j][1];
                if (!uf.is_same(x, 0)) {
                    uf.fa[x] = x;
                }
                if (!uf.is_same(y, 0)) {
                    uf.fa[y] = y;
                }
            }
        }

        // 和 0 在同一个集合的专家都知道秘密
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (uf.is_same(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
