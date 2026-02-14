/* Official Solution 1 */
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[105]={0.0};
        dp[0] = poured;
        for (int i=0; i<105; ++i) {
            if (i == query_row) { //到达查询行，返回结果
                return min(dp[query_glass], 1.0);
            }
            double next[105]={0.0};
            for (int j=0; j<=i; ++j) {
                if (dp[j]>1.0) { //如果大于杯子容量
                    double over = dp[j] - 1.0; //计算溢出
                    next[j]+=over/2.0; //溢出一半流入下一层左边杯子
                    next[j+1]+=over/2.0; //溢出一半流入下一层右边杯子
                }
            }
            for(int j=0; j<105; ++j) {
               dp[j] = next[j];
            }
        }
        return 0.0;
    }
};
