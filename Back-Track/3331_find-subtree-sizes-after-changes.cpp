/* Original Solution 1 */
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> ans(n, n);
        vector<int> backup(parent);
        auto updateParent = [&](int origin, int child, auto& self) {
            int parentId = backup[child];

            if (parentId == -1) {
                return;
            }

            if (s[parentId] != s[origin]) {
                self(origin, parentId, self);
                return ;
            }

            parent[origin] = parentId;
        };


        for (int i = 1; i < n; i++) {
            updateParent(i, i, updateParent);
        }


        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        auto getSubtreeSize = [&](int child, auto& self) -> int {
            int cnt = 1;
            for (int nextChild : children[child]) {
                cnt += self(nextChild, self);
            }

            ans[child] = cnt;
            return cnt;
        };

        getSubtreeSize(0, getSubtreeSize);
        return ans;
    }
};



/* Official Solution 1 */
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g_old(n);
        for (int i = 1; i < n; ++i) {
            g_old[parent[i]].push_back(i);
        }

        vector<vector<int>> records(26);
        vector<int> ans(n);
        function<void(int)> operate = [&](int u) {
            ++ans[u];
            records[s[u] - 'a'].push_back(u);
            for (int v: g_old[u]) {
                operate(v);
                int u_new = records[s[v] - 'a'].empty() ? u : records[s[v] - 'a'].back();
                ans[u_new] += ans[v];
            }
            records[s[u] - 'a'].pop_back();
        };

        operate(0);
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }

        vector<int> size(n, 1);
        int ancestor[26];
        ranges::fill(ancestor, -1);
        auto dfs = [&](this auto&& dfs, int x) -> void {
            int sx = s[x] - 'a';
            int old = ancestor[sx];
            ancestor[sx] = x;
            for (int y : g[x]) {
                dfs(y);
                int anc = ancestor[s[y] - 'a'];
                size[anc < 0 ? x : anc] += size[y];
            }
            ancestor[sx] = old; // 恢复现场
        };
        dfs(0);
        return size;
    }
};
