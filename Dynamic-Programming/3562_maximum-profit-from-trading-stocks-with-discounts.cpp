/* Official Solution 1 */
class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> g(n);

        for (auto& e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }

        auto dfs = [&](auto&& self, int u) -> tuple<vector<int>, vector<int>, int>  {
            int cost = present[u];
            int dCost = present[u] / 2; // discounted cost

            // dp[u][state][budget]
            // state = 0: 不购买父节点, state = 1: 必须购买父节点
            auto dp0 = vector(budget + 1, 0);
            auto dp1 = vector(budget + 1, 0);

            // subProfit[state][budget]
            // state = 0: 优惠不可用, state = 1: 优惠可用
            auto subProfit0 = vector(budget + 1, 0);
            auto subProfit1 = vector(budget + 1, 0);

            int uSize = cost;

            for (auto v : g[u]) {
                auto [subDp0, subDp1, vSize] = self(self, v);
                uSize += vSize;
                for (int i = budget; i >= 0; i--) {
                    for (int sub = 0; sub <= min(vSize, i); sub++) {
                        subProfit0[i] = max(subProfit0[i], subProfit0[i - sub] + subDp0[sub]);
                        subProfit1[i] = max(subProfit1[i], subProfit1[i - sub] + subDp1[sub]);
                    }
                }
            }

            for (int i = 0; i <= budget; i++) {
                dp0[i] = dp1[i] = subProfit0[i];

                if (i >= dCost) {
                    dp1[i] = max(subProfit0[i], subProfit1[i - dCost] + future[u] - dCost);
                }

                if (i >= cost) {
                    dp0[i] = max(subProfit0[i], subProfit1[i - cost] + future[u] - cost);
                }
            }

            return {dp0, dp1, uSize};
        };

        return std::get<0>(dfs(dfs, 0))[budget];
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        // 记录每个父节点都有哪些子节点
        vector<vector<int>> g(n);
        for(auto &e : hierarchy) {
            // 换为下标
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v);
        }

        auto dfs = [&](this auto&& dfs, int x) -> vector<vector<int>> {
            // sub_f[j][k] 表示在花费为 j , 并且 x 有 (k = 1) 或没有 (k = 0) 购买的情况下, x 的所有子树 y 的最大利润总和
            // 初始化为 INT_MIN / 2 利润
            // 注意这里是用 sub_f[j][k] 来与 fy[jy][k] 对接！！！
            vector<vector<int>> sub_f(budget + 1, vector<int>(2, INT_MIN / 2));
            sub_f[0][0] = sub_f[0][1] = 0;

            // 枚举 x 的儿子 y, 让其进入 dfs 求出 sub_fy[j][k]
            for(int y : g[x]) {
                auto fy = dfs(y);
                // 枚举分配给 y 儿子 jy 的花费, 这个 jy 应该小于 j
                // 更新时的语义其实是: 
                // 分配 j 给‘所有目前已经枚举到的儿子’的利润 = 分配 jy 给‘当前这个儿子’得到的利润 + 分配 j - jy 给‘之前遍历到的儿子’得到的利润
                // 注意这里的枚举顺序
                for(int j = budget; j >= 0; j -- ) {
                    for(int jy = 0; jy <= j; jy ++ ) {
                        for(int k = 0; k < 2; k ++ ) {
                            if(sub_f[j - jy][k] < 0) continue; // 优化
                            sub_f[j][k] = max(sub_f[j][k], fy[jy][k] + sub_f[j - jy][k]);
                        }
                    }
                }                
            }

            // 现在 sub_f[j][k] 已经是求好的状态了
            // 开始考虑 x 是否购买
            
            // f[j][k] 表示花费 j, x 的父节点是购买 (k = 1) 或不购买 (k = 1) 的情况下, 从 x 及其子树中能得到的最大利润总和
            vector<vector<int>> f(budget + 1, vector<int>(2, 0));
            
            // 如果 x 不购买
            for(int j = 0; j <= budget; j ++ ) {
                f[j][0] = f[j][1] = sub_f[j][0];
            }

            // 如果 x 购买, 则还需要考虑 k 的情况
            for(int k = 0; k < 2; k ++ ) {
                int c = present[x] / (k + 1);
                for(int j = c; j <= budget; j ++ ) {
                    f[j][k] = max(f[j][k], sub_f[j - c][1] + future[x] - c);
                }
            }

            return f;
        };

        auto f = dfs(0);
        int ans = 0;

        for(int j = 0; j <= budget; j ++ ) {
            ans = max(ans, f[j][0]);
        }
        return ans;
    }
};
