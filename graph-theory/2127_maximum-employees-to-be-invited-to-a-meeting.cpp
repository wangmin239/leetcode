class Solution {
public:
    vector<int> p, sz;
    int maximumInvitations(vector<int>& favorite) {
        unordered_map<int, vector<int>> graph;
        int n = favorite.size();
        p.resize(n);
        sz.resize(n);
        vector<int> deg(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
            graph[i].push_back(favorite[i]);
            deg[favorite[i]]++;
        }
        // 拓扑排序将图剪得只剩环
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 0) q.push(i);
        }
        vector<int> chainlen(n, 1);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int nxt: graph[cur]) {
                chainlen[nxt] = max(chainlen[cur] + 1, chainlen[nxt]);
                if(--deg[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        // 将环合并成一个连通块
        for(int i = 0; i < n; i++) {
            if(deg[i] && deg[favorite[i]]) {
                merge(i, favorite[i]);
            }
        }
        // 求答案
        int ans = 0, temp = 0;
        for(int i = 0; i < n; i++) {
            if(deg[i]) {
                ans = max(ans, sz[find(i)]);
                if(deg[favorite[i]] && sz[find(i)] == 2) {
                    temp += chainlen[i] + chainlen[favorite[i]];
                }
            }
        }
        ans = max(ans, temp>>1);
        return ans;
    }

    int find(int x) {
        return x == p[x]? x: p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx != ry) {
            p[rx] = ry;
            sz[ry] += sz[rx];
        }
    }
};

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        if (n == 0) {
            return 0;
        }
        int indegree[n];
        fill_n(indegree, n, 0);
        int deep[n];  // deep[i] 节点i的最长前置节点链的长度（不包括节点i本身）
        fill_n(deep, n, 0);

        for (int i = 0; i < n; ++i) {
            // edge: i -> favorite[i]
            ++indegree[favorite[i]];
        }
        int queue[n];
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                queue[r++] = i;
            }
        }
        while (l < r) {
            int cur = queue[l++];
            int next = favorite[cur];
            deep[next] = max(deep[next], 1 + deep[cur]);
            if (--indegree[next] == 0) {
                queue[r++] = next;
            }
        }
        // 到目前为止，所有不在环上的点的 in degree 都等于0

        // 可能性1：所有小环（中心点数=2）的中心点数 + 各个中心点最长前置链长度
        int sumOfSmallRings = 0;
        // 可能性2：最大的大环（中心点>2）的中心点数
        int maxBigRingSize = 0;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                continue;
            }
            indegree[i] = 0;
            int ringSize = 1;
            for (int j = favorite[i]; j != i; j = favorite[j]) {
                ++ringSize;
                indegree[j] = 0;
            }
            if (ringSize == 2) {
                sumOfSmallRings += 2 + deep[i] + deep[favorite[i]];
            } else {
                maxBigRingSize = max(maxBigRingSize, ringSize);
            }
        }
        return max(sumOfSmallRings, maxBigRingSize);
    }
};


class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // 统计入度，便于进行拓扑排序
        vector<int> indeg(n);
        for (int i = 0; i < n; ++i) {
            ++indeg[favorite[i]];
        }
        vector<int> used(n), f(n, 1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            used[u] = true;
            q.pop();
            int v = favorite[u];
            // 状态转移
            f[v] = max(f[v], f[u] + 1);
            --indeg[v];
            if (!indeg[v]) {
                q.push(v);
            }
        }
        // ring 表示最大的环的大小
        // total 表示所有环大小为 2 的「基环内向树」上的最长的「双向游走」路径之和
        int ring = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                int j = favorite[i];
                // favorite[favorite[i]] = i 说明环的大小为 2
                if (favorite[j] == i) {
                    total += f[i] + f[j];
                    used[i] = used[j] = true;
                }
                // 否则环的大小至少为 3，我们需要找出环
                else {
                    int u = i, cnt = 0;
                    while (true) {
                        ++cnt;
                        u = favorite[u];
                        used[u] = true;
                        if (u == i) {
                            break;
                        }
                    }
                    ring = max(ring, cnt);
                }
            }
        }
        return max(ring, total);
    }
};
