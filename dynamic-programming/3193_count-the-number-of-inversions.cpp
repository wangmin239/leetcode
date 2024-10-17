class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> reqMap;
        int maxCnt = 0;
        reqMap[0] = 0;
        for (auto& req : requirements) {
            reqMap[req[0]] = req[1];
            maxCnt = max(maxCnt, req[1]);
        }
        if (reqMap[0]) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(maxCnt + 1, -1));
        function<int(int, int)> dfs = [&](int end, int cnt) -> int {
            if (end == 0) {
                return 1;
            }
            if (dp[end][cnt] != -1) {
                return dp[end][cnt];
            }
            if (reqMap.find(end - 1) != reqMap.end()) {
                int r = reqMap[end - 1];
                if (r <= cnt && cnt <= end + r) {
                    return dp[end][cnt] = dfs(end - 1, r);
                } else {
                    return dp[end][cnt] = 0;
                }
            } else {
                int sm = 0;
                for (int i = 0; i <= min(end, cnt); ++i) {
                    sm = (sm + dfs(end - 1, cnt - i)) % MOD;
                }
                return dp[end][cnt] = sm;
            }
        };

        return dfs(n - 1, reqMap[n - 1]);
    }
};
[2, 0, 1]
[2, 1, 0]

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> reqMap;
        int maxCnt = 0;
        reqMap[0] = 0;
        for (auto& req : requirements) {
            reqMap[req[0]] = req[1];
            maxCnt = max(maxCnt, req[1]);
        }
        if (reqMap[0]) {
            return 0;
        }

        vector<vector<long long>> dp(n, vector<long long>(maxCnt + 1, -1));
        function<int(int, int)> dfs = [&](int end, int cnt) -> int {
            if (cnt < 0) {
                return 0;
            }
            if (end == 0) {
                return 1;
            }
            if (dp[end][cnt] != -1) {
                return dp[end][cnt];
            }
            if (reqMap.count(end - 1)) {
                int r = reqMap[end - 1];
                if (r <= cnt && cnt <= end + r) {
                    return dp[end][cnt] = dfs(end - 1, r);
                }
                return 0;
            } else {
                if (cnt > end) {
                    return dp[end][cnt] = (dfs(end, cnt - 1) - dfs(end - 1, cnt - 1 - end) + dfs(end - 1, cnt) + MOD) % MOD;
                } else {
                    return dp[end][cnt] = (dfs(end, cnt - 1) + dfs(end - 1, cnt)) % MOD;
                }
            }
        };

        return dfs(n - 1, reqMap[n - 1]);
    }
};
