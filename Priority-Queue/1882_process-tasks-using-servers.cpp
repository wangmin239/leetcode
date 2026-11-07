/* Original Solution 1 */
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();
        vector<int> ans(n, -1);
        auto greaterCmp = [&](const auto& lhs, const auto& rhs) {
            if (get<0>(lhs) > get<0>(rhs)) {
                return true;
            }

            if (get<0>(lhs) < get<0>(rhs)) {
                return false;
            }


            return get<1>(lhs) != get<1>(rhs) ? get<1>(lhs) > get<1>(rhs) : get<2>(lhs) > get<2>(rhs);
        };

        priority_queue<tuple<long, int, int>, vector<tuple<long, int, int>>, decltype(greaterCmp)> workPq(greaterCmp);
        priority_queue<tuple<long, int, int>, vector<tuple<long, int, int>>, decltype(greaterCmp)> idlePq(greaterCmp);

        for (int i = 0; i < m; i++) {
            idlePq.push({0, servers[i], i});
        }

        long ts = 0;
        auto release = [&]() {
            while (workPq.empty() == false && get<0>(workPq.top()) <= ts) {
                auto [_, weight, id] = workPq.top();
                workPq.pop();
                idlePq.push({0, weight, id});
            }
        };
        for (int i = 0; i < n; i++) {
            ts = max(ts, static_cast<long>(i));
            release();

            if (idlePq.empty() == true) {
                ts = get<0>(workPq.top());
                release();
            }


            auto [_, weight, id] = idlePq.top();
            idlePq.pop();
            workPq.push({ts + tasks[i], weight, id});
            ans[i] = id;
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
private:
    using PLI = pair<long long, int>;
    using PII = pair<int, int>;
    
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        // 工作中的服务器，存储二元组 (t, idx)
        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
        // 空闲的服务器，存储二元组 (w, idx)
        priority_queue<PII, vector<PII>, greater<PII>> idle;
        for (int i = 0; i < m; ++i) {
            idle.emplace(servers[i], i);
        }
        
        long long ts = 0;
        // 将优先队列 busy 中满足 t<=ts 依次取出并放入优先队列 idle
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto&& [_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };
        
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ts = max(ts, static_cast<long long>(i));
            release();
            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }
            auto&& [_, idx] = idle.top();
            ans.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return ans;
    }
};
