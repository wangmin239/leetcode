class Solution {
public:
using pii = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii> > eg(n+1);
        vector<int> vis(n+1);
        int ans = 0;
        for(auto& x: times){
            eg[x[0]].emplace_back(x[1], x[2]);
        }
        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.emplace(0, k);
        while(q.size()){
            auto [time, now] = q.top();
            q.pop();
            if(vis[now])continue;
            ans = max(ans, time);
            vis[now] = true;
            for(auto [next, nextTime]: eg[now]){
                if(vis[next] == false) q.emplace(nextTime + time, next);
            }
        }
        return count(begin(vis)+1, end(vis), true) == n ? ans : -1;
    }
};

