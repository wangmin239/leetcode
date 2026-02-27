
/* Official Solution 1 */
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int z = ranges::count(s, '0');
        if (z == 0) {
            return 0;
        }
        if (k == n) {
            return z == n ? 1 : -1;
        }

        int ans = INT_MAX;
        // 情况一：操作次数 m 是偶数
        if (z % 2 == 0) { // z 必须是偶数
            int m = max((z + k - 1) / k, (z + n - k - 1) / (n - k)); // 下界
            ans = m + m % 2; // 把 m 往上调整为偶数
        }

        // 情况二：操作次数 m 是奇数
        if (z % 2 == k % 2) { // z 和 k 的奇偶性必须相同
            int m = max((z + k - 1) / k, (n - z + n - k - 1) / (n - k)); // 下界
            ans = min(ans, m | 1); // 把 m 往上调整为奇数
        }

        return ans < INT_MAX ? ans : -1;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        set<int> not_vis[2];
        for (int m = 0; m < 2; m++) {
            for (int i = m; i <= n; i += 2) {
                not_vis[m].insert(i);
            }
            not_vis[m].insert(n + 1); // 哨兵，下面无需判断 it != st.end()
        }

        int start = ranges::count(s, '0'); // 起点
        not_vis[start % 2].erase(start);
        vector<int> q = {start};
        for (int ans = 0; !q.empty(); ans++) {
            vector<int> nxt;
            for (int z : q) {
                if (z == 0) { // 没有 0，翻转完毕
                    return ans;
                }
                // not_vis[mn % 2] 中的从 mn 到 mx 都可以从 z 翻转到
                int mn = z + k - 2 * min(k, z);
                int mx = z + k - 2 * max(0, k - n + z);
                auto& st = not_vis[mn % 2];
                for (auto it = st.lower_bound(mn); *it <= mx; it = st.erase(it)) {
                    nxt.push_back(*it);
                }
            }
            q = move(nxt);
        }
        return -1;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size(), m = 0;
        vector<int> dist(n + 1, INT_MAX);
        vector<set<int>> nodeSets(2);
        for (int i = 0; i <= n; i++) {
            nodeSets[i % 2].insert(i);
            if (i < n && s[i] == '0') {
                m++;
            }
        }
        queue<int> q;
        q.push(m);
        dist[m] = 0;
        nodeSets[m % 2].erase(m);
        while (!q.empty()) {
            m = q.front();
            q.pop();
            int c1 = max(k - n + m, 0), c2 = min(m, k);
            int lnode = m + k - 2 * c2, rnode = m + k - 2 * c1;
            auto& nodeSet = nodeSets[lnode % 2];
            for (auto iter = nodeSet.lower_bound(lnode); iter != nodeSet.end() && *iter <= rnode;) {
                int m2 = *iter;
                dist[m2] = dist[m] + 1;
                q.push(m2);
                iter = next(iter);
                nodeSet.erase(m2);
            }
        }
        return dist[0] == INT_MAX ? -1 : dist[0];
    }
};
