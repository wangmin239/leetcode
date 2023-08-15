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


class Solution {
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < k; i++) {
            available.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        vector<int> requests(k, 0);
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                auto[_, id] = busy.top();
                busy.pop();
                available.push(i + ((id - i) % k + k) % k); // 保证得到的是一个不小于 i 的且与 id 同余的数
            }
            if (available.empty()) {
                continue;
            }
            int id = available.top() % k;
            available.pop();
            requests[id]++;
            busy.push({arrival[i] + load[i], id});
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
