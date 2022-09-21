class Solution {
public:
    int minSwap(const string &s1, const string &s2, const int &pos) {
        int tot = 0;
        for (int i = pos; i < s1.size(); i++) {
            tot += s1[i] != s2[i];
        }
        return (tot + 1) / 2;
    }

    int kSimilarity(string s1, string s2) {
        typedef tuple<int, int, int, string> State;
        int n = s1.size();
        priority_queue<State, vector<State>, greater<State>> pq;
        unordered_set<string> visit;
        pq.emplace(0, 0, 0, s1);
        visit.emplace(s1);
        while (!pq.empty()) {
            auto [_, cost, pos, cur] = pq.top();
            pq.pop();
            if (cur == s2) {
                return cost;
            }
            while (pos < n && cur[pos] == s2[pos]) {
                pos++;
            }
            for (int j = pos + 1; j < n; j++) {
                if (s2[j] == cur[j]) {
                    continue;
                }
                if (s2[pos] == cur[j]) {
                    swap(cur[pos], cur[j]);
                    if (!visit.count(cur)) {
                        visit.emplace(cur);
                        pq.emplace(cost + 1 + minSwap(s2, cur, pos + 1), cost + 1, pos + 1, cur);
                    }
                    swap(cur[pos], cur[j]);
                }
            }
        } 
        return 0;
    }
};


class Solution {
public:
    int minSwap(const string &s1, const string &s2, const int &pos) {
        int tot = 0;
        for (int i = pos; i < s1.size(); i++) {
            tot += s1[i] != s2[i];
        }
        return (tot + 1) / 2;
    }

    int kSimilarity(string s1, string s2) {
        string str1, str2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                str1.push_back(s1[i]);
                str2.push_back(s2[i]);
            }
        }
        int n = str1.size();
        if (n == 0) {
            return 0;
        }

        int ans = n - 1;
        function<void(int, int)> dfs = [&](int pos, int cost) {
            if (cost > ans) {
                return;
            }
            while (pos < n && str1[pos] == str2[pos]) {
                pos++;
            }
            if (pos == n) {
                ans = min(ans, cost);
                return;
            }
            /* 当前状态的交换次数下限大于等于当前的最小交换次数 */
            if (cost + minSwap(str1, str2, pos) >= ans) {
                return;
            }
            for (int i = pos + 1; i < n; i++) {
                if (str1[i] == str2[pos]) {
                    swap(str1[i], str1[pos]);
                    dfs(pos + 1, cost + 1);
                    swap(str1[i], str1[pos]);
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
};


class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        queue<pair<string, int>> qu;
        unordered_set<string> visit;
        qu.emplace(s1, 0);
        visit.emplace(s1);
        for (int step = 0;; step++) {
            int sz = qu.size();
            for (int i = 0; i < sz; i++) {
                auto [cur, pos] = qu.front();
                qu.pop();
                if (cur == s2) {
                    return step;
                }
                while (pos < n && cur[pos] == s2[pos]) {
                    pos++;
                }
                for (int j = pos + 1; j < n; j++) {
                    if (cur[j] != s2[j] && cur[j] == s2[pos]) { // 剪枝，只在 cur[j] != s2[j] 时去交换
                        swap(cur[pos], cur[j]);
                        if (!visit.count(cur)) {
                            visit.emplace(cur);
                            qu.emplace(cur, pos + 1);
                        }
                        swap(cur[pos], cur[j]);
                    }
                }
            }
        }
    }
};
