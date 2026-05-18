/* Original Solution 1 */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        vector<bool> memo(n, false);

        auto dfs = [&](int pos, auto&& self) -> bool {

            if (pos < 0 || pos >= n) {
                return false;
            }

            if (arr[pos] == 0) {
                return true;
            }

            if (visited[pos] == true) {
                return memo[pos];
            }

            visited[pos] = true;
            memo[pos] = self(pos + arr[pos], self) || self(pos - arr[pos], self);
            return memo[pos];
        };

        return dfs(start, dfs);
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) {
            return true;
        }
        
        int n = arr.size();
        vector<bool> used(n);
        queue<int> q;
        q.push(start);
        used[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u + arr[u] < n && !used[u + arr[u]]) {
                if (arr[u + arr[u]] == 0) {
                    return true;
                }
                q.push(u + arr[u]);
                used[u + arr[u]] = true;
            }
            if (u - arr[u] >= 0 && !used[u - arr[u]]) {
                if (arr[u - arr[u]] == 0) {
                    return true;
                }
                q.push(u - arr[u]);
                used[u - arr[u]] = true;
            }
        }
        return false;
    }
};
