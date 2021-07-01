class Solution {
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<vector<int>> edges(n);
        for (auto &edge : relation) {
            int src = edge[0], dst = edge[1];
            edges[src].push_back(dst);
        }

        int ways = 0;
        function<void(int, int)> dfs = [&](int index, int steps) {
            if (steps == k) {
                if (index == n - 1) {
                    ++ways;
                }
                return;
            }
            for (int to : edges[index]) {
                dfs(to, steps + 1);
            }
        };
        dfs(0, 0);
        return ways;
    }
};


class Solution {
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<vector<int>> edges(n);
        for (auto &edge : relation) {
            int src = edge[0], dst = edge[1];
            edges[src].push_back(dst);
        }

        int steps = 0;
        queue<int> que;
        que.push(0);
        while (!que.empty() && steps < k) {
            steps++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int index = que.front();
                que.pop();
                for (auto &nextIndex : edges[index]) {
                    que.push(nextIndex);
                }
            }
        }

        int ways = 0;
        if (steps == k) {
            while (!que.empty()) {
                if (que.front() == n - 1) {
                    ways++;
                }
                que.pop();
            }
        }
        return ways;
    }
};



class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < k; i++) {
            for (auto& edge : relation) {
                int src = edge[0], dst = edge[1];
                dp[i + 1][dst] += dp[i][src];
            }
        }
        return dp[k][n - 1];
    }
};

class Solution {
private:
    int num;
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        num = n - 1;
        return getPath(0, relation, k);
    }
    
    
    int getPath(int target, vector<vector<int>>& relation, int k) {
        if (k == 0) {
            return target == num ? 1 : 0;
        }
        vector<int> nextVec;
        for (auto& elem : relation) {
            if (elem[0] == target) {
                nextVec.push_back(elem[1]);
            }
        }
        int sum = 0;
        for (auto& next: nextVec) {
            sum += getPath(next, relation, k - 1);
        }
        return sum;
};

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < k; i++) {
            vector<int> next(n);
            for (auto& edge : relation) {
                int src = edge[0], dst = edge[1];
                next[dst] += dp[src];
            }
            dp = next;
        }
        return dp[n - 1];
    }
};

class Solution {
private:
    int num;
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        num = n - 1;
        return getPath(0, relation, k);
    }
    
    
    int getPath(int target, vector<vector<int>>& relation, int k) {
        if (k == 0) {
            return target == num ? 1 : 0;
        }
        vector<int> nextVec;
        for (auto& elem : relation) {
            if (elem[0] == target) {
                nextVec.push_back(elem[1]);
            }
        }
        int sum = 0;
        for (auto& next: nextVec) {
            sum += getPath(next, relation, k - 1);
        }
        return sum;
    }
};
