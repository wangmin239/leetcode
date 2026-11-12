/* Official Solution 1 */
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        vector<int> ids(queries.size());
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });

        vector<int> ans(queries.size()), cnt(n + 1);
        int left = 0, right = 0, active = 0;
        for (int i : ids) {
            int q = queries[i];
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right++][0];
                if (cnt[id]++ == 0) {
                    ++active;
                }
            }
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left++][0];
                if (--cnt[id] == 0) {
                    --active;
                }
            }
            ans[i] = n - active;
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        ranges::sort(logs, {}, [](auto& p) { return p[1]; }); // 按照 time 排序
        vector<int> idx(queries.size());
        ranges::iota(idx, 0);
        ranges::sort(idx, {}, [&](int i) { return queries[i]; });
        vector<int> cnt(n + 1); // 每个服务器收到了多少个请求
        int not_receives = n; // 没有收到请求的服务器数目
        int left = 0, right = 0;

        for (int qid : idx) {
            int& q = queries[qid];
            // 进入窗口
            while (right < logs.size() && logs[right][1] <= q) {
                int i = logs[right][0];
                if (cnt[i] == 0) {
                    not_receives--;
                }
                cnt[i]++;
                right++;
            }

            // 离开窗口
            while (left < logs.size() && logs[left][1] < q - x) {
                int i = logs[left][0];
                cnt[i]--;
                if (cnt[i] == 0) {
                    not_receives++;
                }
                left++;
            }

            q = not_receives;
        }

        return queries;
    }
};
