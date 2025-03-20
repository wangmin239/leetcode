class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> ban{banned.begin(), banned.end()};
        set<int> sets[2];
        for (int i = 0; i < n; ++i) {
            if (i != p && !ban.count(i)) {
                sets[i % 2].insert(i);
            }
        }
        vector<int> ans(n, -1);
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int mn = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            auto it = sets[mx % 2].lower_bound(mn);
            while (it != sets[mx % 2].end()) {
                if (*it > mx) {
                    break;
                }
                ans[*it] = ans[i] + 1;
                q.push(*it);
                it = sets[mn % 2].erase(it);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int find(vector<int>& f, int x) {
        return f[x] == x ? x : f[x] = find(f, f[x]);
    }
    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
    }
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<vector<int>> fa(2, vector<int>(n + 2));
        iota(fa[0].begin(), fa[0].end(), 0);
        iota(fa[1].begin(), fa[1].end(), 0);
        for (int ban : banned) {
            merge(fa[ban % 2], ban, ban + 2);
        }
        vector<int> ans(n, -1);
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        merge(fa[p % 2], p, p + 2);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int mn = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            for (int j = mn; j <= mx;) {
                int fi = find(fa[mn % 2], j);
                if (fi > mx) {
                    break;
                }
                ans[fi] = ans[i] + 1;
                q.push(fi);
                merge(fa[mn % 2], fi, fi + 2);
                j = fi + 2;
            }
        }
        return ans;
    }
};
