/* Official Solution 1 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> suffix_sum(n);
        suffix_sum[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + stoneValue[i];
        }

        vector<int> f(n + 1);
        // 边界情况，当没有石子时，分数为 0
        // 为了代码的可读性，显式声明
        f[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int bestj = f[i + 1];
            for (int j = i + 2; j <= i + 3 && j <= n; ++j) {
                bestj = min(bestj, f[j]);
            }
            f[i] = suffix_sum[i] - bestj;
        }
        
        if (int total = accumulate(stoneValue.begin(), stoneValue.end(), 0); f[0] * 2 == total) {
            return "Tie";
        }
        else {
            return f[0] * 2 > total ? "Alice" : "Bob";
        }
    }
};


/* Official Solution 2 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> f(n + 1, INT_MIN);
        // 边界情况，当没有石子时，分数为 0
        f[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int pre = 0;
            for (int j = i + 1; j <= i + 3 && j <= n; ++j) {
                pre += stoneValue[j - 1];
                f[i] = max(f[i], pre - f[j]);
            }
        }
        
        if (f[0] == 0) {
            return "Tie";
        }
        else {
            return f[0] > 0 ? "Alice" : "Bob";
        }
    }
};


/* Official Solution 3 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(n, INT_MIN); // INT_MIN 表示该状态没有计算过

        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i == n) {
                return 0;
            }

            int& res = memo[i]; // 注意这里是引用
            if (res != INT_MIN) { // 之前计算过
                return res;
            }

            int sum = 0;
            for (int j = i; j < min(i + 3, n); j++) {
                sum += stoneValue[j];
                res = max(res, sum - dfs(j + 1));
            }
            return res;
        };

        int diff = dfs(0);
        if (diff == 0) {
            return "Tie";
        }
        return diff > 0 ? "Alice" : "Bob";
    }
};


/* Official Solution 4 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> f(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            f[i] = INT_MIN;
            int sum = 0;
            for (int j = i; j < min(i + 3, n); j++) {
                sum += stoneValue[j];
                f[i] = max(f[i], sum - f[j + 1]);
            }
        }

        int diff = f[0];
        if (diff == 0) {
            return "Tie";
        }
        return diff > 0 ? "Alice" : "Bob";
    }
};

/* Official Solution 5 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int suf_sum = 0, f1 = 0, f2 = 0, f3 = 0;
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            suf_sum += stoneValue[i];
            int new_f = suf_sum - min(min(f1, f2), f3); // 这样写比 min({f1, f2, f3}) 更快
            f3 = f2;
            f2 = f1;
            f1 = new_f;
        }

        int diff = f1 - (suf_sum - f1);
        if (diff == 0) {
            return "Tie";
        }
        return diff > 0 ? "Alice" : "Bob";
    }
};
