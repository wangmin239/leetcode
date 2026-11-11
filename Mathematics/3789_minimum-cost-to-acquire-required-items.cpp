/* Original Solution 1 */
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minCost = LONG_MAX;

        minCost = min(minCost, 1LL * cost1 * need1 + 1LL * cost2 * need2);
        minCost = min(minCost, 1LL * costBoth * max(need1, need2));

        if (need1 > need2) {
            minCost = min(minCost, 1LL * costBoth * need2 + 1LL * cost1 * (need1 - need2));
        } else {
            minCost = min(minCost, 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1));
        }

        return minCost;
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;

        // 分别购买更便宜，不需要物品 3
        if (cost1 + cost2 <= costBoth) {
            totalCost = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }
        else {
            // 优先购买物品 3，直到一种需求满足
            int cnt_3 = min(need1, need2);
            totalCost = 1LL * cnt_3 * costBoth;

            need1 -= cnt_3;
            need2 -= cnt_3;

            // 类型 1 的需求还未被满足，选择物品 1 或物品 3 中更便宜的
            if (need1 > 0) {
                totalCost += 1LL * need1 * min(cost1, costBoth);
            }

            // 类型 2 的需求还未被满足，选择物品 2 或物品 3 中更便宜的
            else if (need2 > 0) {
                totalCost += 1LL * need2 * min(cost2, costBoth);
            }
        }

        return totalCost;
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res1 = 1LL * cost1 * need1 + 1LL * cost2 * need2; // 各买各的
        if (need1 > need2) {
            swap(need1, need2);
            cost2 = cost1;
        }
        long long res2 = 1LL * costBoth * need2; // 我包了
        long long res3 = 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1); // 混合策略
        return min({res1, res2, res3});
    }
};
