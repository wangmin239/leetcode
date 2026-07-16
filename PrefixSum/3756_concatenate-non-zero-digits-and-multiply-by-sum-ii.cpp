/* Original Solution 1 */
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int len = s.length();
        int n = queries.size();
        vector<int> ans(n, 0);
        const int mod = 1e9 + 7;
        const int decimal = 10;

        vector<int> preSum(len + 1, 0);
        vector<int> xPos(len + 1, 0);
        string noZeroStr;
        
        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';

            preSum[i + 1] += preSum[i] + digit;


            if (digit != 0) {
               noZeroStr.push_back(s[i]);
            }
            xPos[i + 1] = noZeroStr.length();
        }

        int j = 0;
        for (const auto& query : queries) {
            int left = query.front();
            int right = query.back();

            int curSum = preSum[right + 1] - preSum[left];
            long long x = 0;

            for (size_t i = xPos[left]; i < xPos[right + 1]; i++) {
                int digit =noZeroStr[i] - '0';

                x *= decimal;
                x += digit;
                x %= mod;

            }
            ans[j++] = x * (curSum % mod) % mod ;

        }

        return ans;
    }
};


/* Official Solution 1 */
const int MOD = 1e9 + 7;
const int MAX_N = 100001;
long long pow10[MAX_N];

// init 对于所有测试用例只运行一次
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1, 0);
        vector<long long> x(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            x[i + 1] = (d > 0) ? (x[i] * 10 + d) % MOD : x[i];
            cnt[i + 1] = cnt[i] + (d > 0);
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];
            long long val_x = (x[r] - x[l] * pow10[length] % MOD + MOD) % MOD;
            long long val_sum = sum[r] - sum[l];
            res[i] = (val_x * val_sum) % MOD;
        }
        return res;
    }
};
