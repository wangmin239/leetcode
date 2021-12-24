class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> records;
        
        int res = 0;
        for (int i = 0; i < n || records.size(); ++i) {
            if (i < n && apples[i] > 0) {
                records.emplace(i + days[i], apples[i]);   
            }
            
            while (records.size() && records.top().first <= i) {
                records.pop();
            }
            
            if (records.size()) {
                res += 1;
                pair<int, int> cur = records.top();
                records.pop();
                cur.second -= 1;
                
                if (cur.second != 0) {
                    records.push(cur);
                }
            }
        }
        
        return res;
    }
};

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int eats = 0, time = 0, n = apples.size();
        map<int, int> m;
        for(; time < n; ++time){
            if(apples[time]) m[days[time] + time] += apples[time];
            if(m.empty()) continue;
            if(!--m.begin()->second) m.erase(begin(m));
            m.erase(time+1);
            ++eats;
        }
        int deadline = INT_MAX;
        while(!m.empty()){ /* 很奇怪这里为什么边弹出边遍历居然比直接逆序遍历要快。。难道map的迭代器自增效率很低吗 */
            auto [e, a] = *m.rbegin();
            deadline = min(deadline, e);
            m.erase(prev(m.end()));
            int cost = min(deadline - time, a);
            eats += cost;
            deadline -= cost;
        }
        return eats;
    }
};

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        using pii = pair<int, int>;
        
        int ans = 0;
        int curDay = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        while (curDay < apples.size()) {
            while (pq.empty() == false && pq.top().first <= curDay) {
                pq.pop();
            }
            
            int rottenDay = curDay + days[curDay];
            int num = apples[curDay];
            
            if (num > 0) {
                pq.emplace(rottenDay, num);
            }
            
            if (pq.empty() == false) {
                auto cur = pq.top();
                pq.pop();
                cur.second--;
                
                if (cur.second != 0) {
                    pq.emplace(cur.first, cur.second);
                }
                ans++;
            }
            curDay++;
        }
        
        while (pq.empty() == false) {
            while (pq.empty() == false && pq.top().first <= curDay) {
                pq.pop();
            }
            if (pq.empty() == true) {
                break;
            }
            auto cur = pq.top();
            pq.pop();
            int num = min(cur.first - curDay, cur.second);
            ans += num;
            curDay += num;
        }
        return ans;
    }
};
