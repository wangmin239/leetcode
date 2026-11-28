/* Official Solution 1 */
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int mx = 0;
        for (const auto& item : items) {
            mx = max(mx, item[0]);
        }
        vector<int> freq(mx + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        for (int i = 1; i <= mx; i++) {
            if (freq[i] > 0) {
                for (int j = i * 2; j <= mx; j += i) {
                    freq[i] += freq[j];
                }
            }
        }

        int mn = items[0][1];
        int ans = 0;
        for (const auto& item : items) {
            int factor = item[0], price = item[1];
            if (price - mn > mn) {
                break;
            }
            int cnt = freq[factor] - 1;
            int take = min(cnt, budget / price);
            ans += take * 2;
            budget -= take * price;
        }
        ans += budget / mn;
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt_factor(n + 1);
        int min_price = INT_MAX;
        for (auto& p : items) {
            cnt_factor[p[0]]++;
            min_price = min(min_price, p[1]);
        }
        vector<int> cnt_multi(n + 1);
        map<int, long long> sum_cnt;

        for (auto& p : items) {
            int factor = p[0], price = p[1];
            if (price >= min_price * 2) {
                continue;
            }

            int& cnt = cnt_multi[factor]; // 注意这里是引用
            if (cnt == 0) { // 之前没有计算过
                for (int j = factor; j <= n; j += factor) {
                    cnt += cnt_factor[j];
                }
            }

            if (cnt > 1) {
                sum_cnt[price] += cnt - 1; // factor 的倍数不包括该物品
            }
        }

        int ans = 0;
        for (auto& [price, cnt] : sum_cnt) {
            if (budget < price) { // 没钱了
                break;
            }
            int c = min(cnt, 1LL * budget / price); // 该物品最多买 c 个
            budget -= price * c;
            ans += c * 2;
        }
        return ans + budget / min_price; // 剩余的钱买最便宜的物品
    }
};
