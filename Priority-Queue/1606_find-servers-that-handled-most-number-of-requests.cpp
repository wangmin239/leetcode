/* Official Solution 1 */
class Solution {
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(p);
        }
        int maxRequest = *max_element(requests.begin(), requests.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxRequest) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // 小优化：如果 k >= n，我们只会用到前 n 台服务器，且每台服务器恰好使用一次
        int n = arrival.size();
        if (k >= n) {
            vector<int> ans(n);
            ranges::iota(ans, 0);
            return ans;
        }

        // 初始化空闲服务器堆，保存空闲服务器的虚拟编号
        priority_queue<int, vector<int>, greater<>> idle;
        for (int i = 0; i < k; i++) {
            idle.push(i);
        }

        // 繁忙服务器堆，保存 (服务器完成请求的时刻, 服务器编号)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy; 
        vector<int> cnt(k); // cnt[i] 统计服务器 i 处理的请求数
        int max_cnt = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // 把已经完成请求的服务器从 busy 移至 idle
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                auto [_, j] = busy.top();
                busy.pop();
                // 把服务器 j 在 [i,i+k) 中的同余值 virtual_id 作为该服务器的虚拟编号
                int virtual_id = i + (j - i % k + k) % k; // +k 保证取模结果非负
                idle.push(virtual_id);
            }

            // 没有空闲服务器，舍弃该请求
            if (idle.empty()) {
                continue;
            }

            int j = idle.top() % k;
            idle.pop();
            busy.emplace(arrival[i] + load[i], j);

            cnt[j]++;
            if (cnt[j] > max_cnt) { // j 是最繁忙的服务器
                max_cnt = cnt[j];
                ans = {j};
            } else if (cnt[j] == max_cnt) { // j 是最繁忙的服务器之一
                ans.push_back(j);
            }
        }

        return ans;
    }
};
