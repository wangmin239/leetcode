/* Official Solution 1 */
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> f(budget + 1, 0);
        int mn = INT_MAX;
        for (const auto& item : items) {
            int factor = item[0], price = item[1];
            mn = min(mn, price);
            int cnt = 0;
            for (const auto& other : items) {
                if (other[0] % factor == 0) {
                    cnt++;
                }
            }
            for (int j = budget; j >= price; j--) {
                f[j] = max(f[j], f[j - price] + cnt);
            }
        }
        int ans = 0;
        for (int j = 0; j <= budget; j++) {
            ans = max(ans, f[j] + (budget - j) / mn);
        }
        return ans;
    }
};


/* Original Solution 1, 754 / 764 testcases passed */
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<tuple<double, int, int>> bonusItems;
        int minCost = INT_MAX;
        auto getBonus = [&](int id) {
            int cnt = 0;
            int factor = items[id].front();

            for (int i = 0; i < n; i++) {
                if (i == id) {
                    continue;
                }

                if (items[i].front() % factor == 0) {
                    ++cnt;
                }
            }

            return cnt;
        };

        for (int i = 0; i < n; i++) {
            int cnt = getBonus(i);

            if (cnt > 0) {
                double cost = static_cast<double>(items[i].back()) / (cnt + 1);
                bonusItems.emplace_back(cost, items[i].back(), cnt + 1);
            }
            minCost = min(minCost, items[i].back());
        }

        sort(bonusItems.begin(), bonusItems.end(), [&](const auto& lhs, const auto& rhs) {
            return get<0>(lhs)  < get<0>(rhs);
        });

        int ans = 0;

        for (size_t i = 0; i < bonusItems.size(); i++) {
            if (budget < get<1>(bonusItems[i])) {
                break;
            }

            double curCost = get<0>(bonusItems[i]);

            if (curCost >= static_cast<double>(minCost)) {
                break;
            }

            ans += get<2>(bonusItems[i]);
            budget -= get<1>(bonusItems[i]);

        }

        return ans + budget / minCost;
    }
};



class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<bool> bonus(n, false);

        auto getBonus = [&](int id) {
            int cnt = 0;
            int factor = items[id].front();

            for (int i = 0; i < n; i++) {
                if (i == id) {
                    continue;
                }

                if (items[i].front() % factor == 0) {
                    ++cnt;
                }
            }
            bonus[id] = true;
            return cnt;
        };


        auto dfs = [&](int curBudget, auto&& self) -> int{
                int maxCnt = 0;
                for (int i = 0; i < n; i++) {
                    if (curBudget < items[i].back()) {
                        continue;
                    }

                    int cnt = 1;

                    if (bonus[i] == false) {
                        cnt += getBonus(i);
                    }

                    maxCnt = max(maxCnt, cnt + self(curBudget - items[i].back(), self));
                }

                return maxCnt;
        };

        return dfs(budget, dfs);
    }
};

