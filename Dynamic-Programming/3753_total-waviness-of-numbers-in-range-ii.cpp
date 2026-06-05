/* Official Solution 1 */
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        using ll = long long;
        // 计算 [0, num] 内所有数字的波动值总和
        auto solve = [&](ll num) -> ll {
            // 如果少于 3 的数字波动值 0
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();
            
            // 记忆化搜索使用两个独立的数组
            // memo_cnt[pos][x][y]：当前位为 pos 位，且前两位为 x, y 的合法填充方案数
            ll memo_cnt[16][10][10];
            // memo_sum[pos][x][y]：当前位为 pos 位，且左边两位为 x, y 的波动值
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));
            
            auto dfs = [&](this auto &&dfs, int pos, int prev, int curr, bool isLimit, bool isLeading) -> pair<ll,ll> {
                // 结束位置
                if (pos == n) {
                    return {1, 0};
                }
                // 只有在不受上限限制且不包含前导零时才使用记忆化
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]};
                    }
                }
                
                // 计算当前条件下的方案数和波动值
                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLeading = isLeading && (digit == 0);
                    // 前一个数字更新为 curr
                    int newPrev = curr;
                    // 当前数字更新为 digit
                    int newCurr = newLeading ? -1 : digit;
                    auto [subCnt, subSum] = dfs(pos + 1, newPrev, newCurr, isLimit && (digit == up), newLeading);
                    // 不包含前导零时才计算波动值
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        // 数位为峰或为谷时，更新当前的波动值
                        if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }
                    
                    cnt += subCnt;
                    sum += subSum;
                }
                
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    // 更新记忆化数组
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }
                
                return {cnt, sum};
            };
            
            // 修正：传递 dfs 作为第一个参数
            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };
        
        return solve(num2) - solve(num1 - 1);
    }
};

/* Official Solution 2 */
class Solution {
public:
    using ll = long long;

    struct State {
        int prev, curr, tight, lead;
        ll cnt, sum;
    };

    ll solve(ll num) {
        // 数字小于 3 位波动值为 0
        if (num < 100) {
            return 0;
        }
        string s = to_string(num);
        int n = s.size();
   
        vector<State> currStates;
        // 数位 10 表示存在前导零时的无效无效状态
        currStates.push_back({10, 10, 1, 1, 1, 0});
        for (int pos = 0; pos < n; ++pos) {
            int limit = s[pos] - '0';
            ll cnt[2][2][11][11] = {0};
            ll sum[2][2][11][11] = {0};
            
            for (const auto& st : currStates) {
                int maxDigit = st.tight ? limit : 9;
                for (int digit = 0; digit <= maxDigit; ++digit) {
                    int newLead = st.lead && (digit == 0);
                    int newPrev = st.curr;
                    int newCurr = newLead ? 10 : digit;
                    int newTight = st.tight && (digit == maxDigit);
                    
                    ll add = 0;
                    // 已有三位有效数字时才计算波动（prev和curr都有效，且不是前导零）
                    if (!newLead && st.prev != 10 && st.curr != 10) {
                        if ((st.prev < st.curr && st.curr > digit) || 
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }
                    
                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }
            
            // 收集合法状态
            vector<State> nextStates;
            for (int tight = 0; tight < 2; ++tight) {
                for (int lead = 0; lead < 2; ++lead) {
                    for (int prev = 0; prev <= 10; ++prev) {
                        for (int curr = 0; curr <= 10; ++curr) {
                            ll c = cnt[tight][lead][prev][curr];
                            ll s = sum[tight][lead][prev][curr];
                            // 如何当前为有效状态，则进入下一轮计算
                            if (c != 0) {
                                nextStates.push_back({prev, curr, tight, lead, c, s});
                            }
                        }
                    }
                }
            }
            
            currStates.swap(nextStates);
        }

        // 累加所有合法状态的波动值之和
        ll ans = 0;
        for (const auto& st : currStates) {
            ans += st.sum;
        }
        return ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};


/* Official Solution 3 */
class Solution {
    // 计算 [1, n] 中的整数的波动值之和
    long long calc(long long n) {
        long long ans = 0;

        // 把整数划分成五段：prefix | l | m | r | suffix
        // 从低到高枚举 (l, m, r) 的位置，计算 (l, m, r) 对答案的贡献
        for (long long pow10 = 1; n >= pow10 * 100; pow10 *= 10) {
            long long max_prefix = n / (pow10 * 1000);
            long long n2 = n / pow10;
            int L = n2 / 100 % 10;
            int M = n2 / 10 % 10;
            int R = n2 % 10;

            // 1. prefix < max_prefix 时，低位不受约束
            // 但 prefix=0 且 l=0 的情况是不合法的，需要减掉
            long long cnt = max_prefix * 570 - 45; // 先不与 pow10 相乘

            // 2. prefix = max_prefix 且 l < L
            cnt += (121 + L * 15 - L * L) * L / 3;

            // 3. prefix = max_prefix 且 l = L 且 m < M
            cnt += (L + M) * max(M - L - 1, 0) / 2;  // 峰
            cnt += (19 - min(L, M)) * min(L, M) / 2; // 谷

            // 4. prefix = max_prefix 且 l = L 且 m = M 且 r < R
            if (L < M) { // 只能是峰
                cnt += min(M, R);
            } else if (L > M) { // 只能是谷
                cnt += max(R - M - 1, 0);
            }

            // 到此为止，suffix 可以随便填，有 pow10 种填法
            ans += cnt * pow10;

            // 5. prefix = max_prefix 且 l = L 且 m = M 且 r = R
            if ((L - M) * (M - R) < 0) { // 峰或谷
                long long max_suffix = n % pow10;
                ans += max_suffix + 1; // suffix 可以填 [0, max_suffix] 中的任意整数
            }
        }

        return ans;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};


/* Official Solution 4 */
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        string low_s = to_string(num1);
        string high_s = to_string(num2);
        int n = high_s.size();
        int diff_lh = n - low_s.size();
        vector memo(n, vector<array<array<long long, 10>, 3>>(n));

        auto dfs = [&](this auto&& dfs, int i, int waviness, int last_cmp, int last_digit, bool limit_low, bool limit_high) -> long long {
            if (i == n) {
                return waviness;
            }
            long long& ref = memo[i][waviness][last_cmp + 1][last_digit];
            if (!limit_low && !limit_high && ref) {
                return ref - 1;
            }

            int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;

            long long res = 0;
            bool is_num = !limit_low || i > diff_lh; // 前面是否填过数字
            for (int d = lo; d <= hi; d++) {
                // 当前填的数不是最高位，cmp 才有意义
                int cmp = is_num ? (d > last_digit) - (d < last_digit) : 0;
                int w = waviness + (cmp * last_cmp < 0);
                res += dfs(i + 1, w, cmp, d, limit_low && d == lo, limit_high && d == hi);
            }

            if (!limit_low && !limit_high) {
                ref = res + 1;
            }
            return res;
        };

        return dfs(0, 0, 0, 0, true, true);
    }
};
