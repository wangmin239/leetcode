/* Official Solution 1 */
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;
        // 增加限制 (1, 0)
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        // 增加限制 (n, n-1)
        if (r.back()[0] != n) {
            r.push_back({n, n - 1});
        }

        int m = r.size();
        
        // 从左向右传递限制
        for (int i = 1; i < m; ++i) {
            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
        }
        // 从右向左传递限制
        for (int i = m - 2; i >= 0; --i) {
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }
            
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            // 计算 r[i][0] 和 r[i][1] 之间的建筑的最大高度
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = max(ans, best);
        }
        
        return ans;
    }
};
