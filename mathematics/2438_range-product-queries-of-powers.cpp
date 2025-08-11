/* Original Solution 1 */
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int len = queries.size();
        const int mod = 1e9 + 7;
        vector<int> power;
        
        while (n > 0) {
            int i;
            for (i = 29; i >= 0; i--) {
                if (n >= (1 << i)) {
                    break;
                }
            }
            int value = 1 << i;
            n -= value;
            power.push_back(value);
        }
        
        
        sort(power.begin(), power.end());
        int size = power.size();
        
        vector<int> ans(len, 1);
        for (int i = 0; i < len; i++) {
            int left = queries[i].front();
            int right = queries[i].back();
            while (left <= right) {
                ans[i] = 1LL * power[left++] * ans[i] % mod;
            }
        }
        
        return ans;
    }
};

/* Official Solution 1 */
const int MOD = 1'000'000'007;
const int MX = 436;
int pow2[MX] = {1};

int init = [] {
    for (int i = 1; i < MX; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> s = {0};
        for (; n > 0; n &= n - 1) { // n &= n-1 去掉 n 的最低比特 1
            int e = countr_zero((uint32_t) n);
            // 直接计算 e 的前缀和
            s.push_back(s.back() + e);
        }

        vector<int> ans;
        ans.reserve(queries.size()); // 预分配空间
        for (auto& q : queries) {
            int sum_e = s[q[1] + 1] - s[q[0]];
            ans.push_back(pow2[sum_e]);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n % 2 == 1) {
                bins.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int m = bins.size();
        vector<vector<int>> results(m, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            int cur = 1;
            for (int j = i; j < m; ++j) {
                cur = static_cast<long long>(cur) * bins[j] % mod;
                results[i][j] = cur;
            }
        }

        vector<int> ans;
        for (const auto& query: queries) {
            ans.push_back(results[query[0]][query[1]]);
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};











