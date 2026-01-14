class Solution {
public:
    using ump = unordered_map<int, int>;
    static constexpr int mod = 1e9 + 7;
    static constexpr int inf = 0x3f3f3f3f;
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<vector<ump>> d(n, vector<ump>(k + 1));
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            d[i][1][inf] = 1;
            for (int j = 0; j < i; j++) {
                int diff = abs(nums[i] - nums[j]);
                for (int p = 2; p <= k; p++) {
                    for (auto &[v, cnt] : d[j][p - 1]) {
                        d[i][p][min(diff, v)] = (d[i][p][min(diff, v)] + cnt) % mod;
                    }
                }
            }

            for (auto &[v, cnt] : d[i][k]) {
                res = (res + 1ll * v * cnt % mod) % mod;
            }
        }
        return res;
    }
};

class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    static constexpr int inf = 0x3f3f3f3f;
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> vals;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                vals.push_back(nums[i] - nums[j]);
            }
        }
        vals.push_back(inf);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<vector<vector<int>>> d(n, vector(k + 1, vector(vals.size(), 0)));
        vector<vector<int>> border(n, vector(k + 1, 0));
        vector<vector<int>> sum(k + 1, vector(vals.size(), 0));
        vector<vector<int>> suf(n, vector(k + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int pos = lower_bound(vals.begin(), vals.end(), nums[i] - nums[j]) - vals.begin();
                for (int p = 1; p <= k; p++) {
                    while (border[j][p] < pos) {
                        sum[p][border[j][p]] = (sum[p][border[j][p]] - suf[j][p] + mod) % mod;
                        sum[p][border[j][p]] = (sum[p][border[j][p]] + d[j][p][border[j][p]]) % mod;
                        suf[j][p] = (suf[j][p] - d[j][p][border[j][p]] + mod) % mod;
                        border[j][p]++;
                        sum[p][border[j][p]] = (sum[p][border[j][p]] + suf[j][p]);
                    }
                }
            }

            d[i][1][vals.size() - 1] = 1;
            for (int p = 2; p <= k; p++) {
                for (int v = 0; v < vals.size(); v++) {
                    d[i][p][v] = sum[p - 1][v];
                }
            }
            for (int p = 1; p <= k; p++) {
                for (int v = 0; v < vals.size(); v++) {
                    suf[i][p] = (suf[i][p] + d[i][p][v]) % mod;
                }
                sum[p][0] = (sum[p][0] + suf[i][p]) % mod;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int v = 0; v < vals.size(); v++) {
                res = (res + 1ll * vals[v] * d[i][k][v] % mod) % mod;
            }
        }
        return res;
    }
};
