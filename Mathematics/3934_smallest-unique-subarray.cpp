/* Official Solution 1 */
using ll = long long;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        constexpr ll MOD = 1000000007LL;
        constexpr ll BASE = 911382323LL;

        int n = (int)nums.size();
        vector<ll> h(n + 1);
        vector<ll> p(n + 1);
        p[0] = 1;

        // 计算 哈希前缀 + BASE 的幂次前缀
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (h[i] * BASE + nums[i]) % MOD;
            p[i + 1] = p[i] * BASE % MOD;
        }

        auto check = [&](int len) {
            unordered_map<ll, int> cnt;
            cnt.reserve(n - len + 1);

            for (int l = 0; l + len <= n; ++l) {
                int r = l + len;

                ll key = (h[r] - h[l] * p[len] % MOD + MOD) % MOD;
                ++cnt[key];
            }

            for (auto& [key, times] : cnt) {
                if (times == 1) {
                    return true;
                }
            }
            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> sa(n), rank(nums.begin(), nums.end());
        vector<int> nextRank(n);

        iota(sa.begin(), sa.end(), 0);

        // 倍增构造排序后的后缀数组
        int maxRank = *max_element(nums.begin(), nums.end());
        vector<int> temp(n), cnt(std::max(n + 1, maxRank + 2));

        auto counting_sort = [&](auto get_key) {
            fill(cnt.begin(), cnt.end(), 0);

            for (int i : sa) {
                ++cnt[get_key(i)];
            }

            for (int i = 1; i <= maxRank + 1; ++i) {
                cnt[i] += cnt[i - 1];
            }

            for (int p = n - 1; p >= 0; --p) {
                int i = sa[p];
                temp[--cnt[get_key(i)]] = i;
            }

            sa.swap(temp);
        };

        for (int k = 1; k < n; k <<= 1) {
            auto get_rank = [&](int i) -> pair<int, int> {
                return {rank[i], i + k < n ? rank[i + k] : -1};
            };
            
            // 先按第二关键字排序，再按第一关键字稳定排序
            counting_sort([&](int i) { return get_rank(i).second + 1; });
            counting_sort([&](int i) { return get_rank(i).first + 1; });

            nextRank[sa[0]] = 0;

            // 给排序后的新后缀分配排名
            for (int i = 1; i < n; ++i) {
                auto rx = get_rank(sa[i - 1]), ry = get_rank(sa[i]);
                nextRank[sa[i]] = nextRank[sa[i - 1]] + (rx != ry);
            }

            rank.swap(nextRank);
            maxRank = rank[sa.back()];

            // n 个后缀有 n 个排名，排名各不相同，说明排序完毕
            if (maxRank == n - 1) {
                break;
            }
        }

        // Kasai 算法构造 LCP
        vector<int> pos(n), lcp(n, 0);
        for (int i = 0; i < n; ++i) {
            pos[sa[i]] = i;
        }

        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (pos[i] == 0) {
                h = 0;
                continue;
            }

            int j = sa[pos[i] - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                ++h;
            }

            lcp[pos[i]] = h;

            if (h > 0) {
                --h;
            }
        }

        int answer = n;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1 < n ? lcp[i + 1] : 0);

            int need = std::max(lcp[i], next) + 1;
            if (sa[i] + need - 1 < n) {
                answer = std::min(answer, need);
            }
        }

        return answer;
    }
};
