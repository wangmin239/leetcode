class Solution {
private:
    static constexpr int INF = 10000 * 101 + 1;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> f(k + 2, vector<int>(n, INF));
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t) {
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = min(f[t][i], f[t - 1][j] + cost);
            }
        }
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            ans = min(ans, f[t][dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};


class Solution {
private:
    static constexpr int INF = 10000 * 101 + 1;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> f(n, INF);
        f[src] = 0;
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            vector<int> g(n, INF);
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                g[i] = min(g[i], f[j] + cost);
            }
            f = move(g);
            ans = min(ans, f[dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 0x3f3f3f3f);
        vector<vector<int>> e(n);
        queue<int> q;
        int sq;

        for(auto& x: flights) e[x[0]].push_back((x[1] << 16) + x[2]);
        dp[src] = 0;
        q.push(src);
        while(1+k-- && (sq = q.size())){
            vector<bool> vis(n);
            vector<int> cpy = dp;
            while(sq--){
                int now = q.front();
                for(auto x: e[now]){
                    int next = x>>16, v = x&0xffff;
                    cpy[next] = min(cpy[next], dp[now] + v);
                    if(vis[next]) continue;
                    vis[next] = 1;
                    q.push(next);
                }
                q.pop();
            }
            dp = move(cpy);
        }
        return dp[dst] == 0x3f3f3f3f ? -1 : dp[dst];
    }
};