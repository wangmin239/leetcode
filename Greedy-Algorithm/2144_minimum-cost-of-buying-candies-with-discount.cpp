/* Original Solution 1 */
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        const int step = 3;
        int totalCost = 0;
        int maxGroup = step * (n / step);

        sort(cost.begin(), cost.end(), greater<int>());

        for (int i = 0; i < maxGroup; i += step) {
            totalCost += cost[i] + cost[i + 1];
        }

        for (int i = maxGroup; i < n; i++) {
            totalCost += cost[i];
        }

        return totalCost;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int res = 0;
        int n = cost.size();
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) {
                res += cost[i];
            }
        }
        return res;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost);

        int ans = 0;
        // 从大到小，买两个送一个
        for (int i = cost.size() - 1; i >= 0; i -= 3) {
            ans += cost[i];
            if (i > 0) {
                ans += cost[i - 1];
            }
        }
        return ans;
    }
};
