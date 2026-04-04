/* Official Solution 1 */
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;

        if (startPos[0] < homePos[0]) {
            for (int x = startPos[0] + 1; x <= homePos[0]; x++) {
                cost += rowCosts[x];
            }
        } else if (startPos[0] > homePos[0]) {
            for (int x = startPos[0] - 1; x >= homePos[0]; x--) {
                cost += rowCosts[x];
            }
        }

        if (startPos[1] < homePos[1]) {
            for (int y = startPos[1] + 1; y <= homePos[1]; y++) {
                cost += colCosts[y];
            }
        } else if (startPos[1] > homePos[1]) {
            for (int y = startPos[1] - 1; y >= homePos[1]; y--) {
                cost += colCosts[y];
            }
        }

        return cost;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        int res = 0;   // 总代价
        // 移动至家所在行，判断行间移动方向并计算对应代价
        if (r2 >= r1){
            res += accumulate(rowCosts.begin() + r1 + 1, rowCosts.begin() + r2 + 1, 0);
        }
        else{
            res += accumulate(rowCosts.begin() + r2, rowCosts.begin() + r1, 0);
        }
        // 移动至家所在位置，判断列间移动方向并计算对应代价
        if (c2 >= c1){
            res += accumulate(colCosts.begin() + c1 + 1, colCosts.begin() + c2 + 1, 0);
        }
        else{
            res += accumulate(colCosts.begin() + c2, colCosts.begin() + c1, 0);
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int x0 = startPos[0], y0 = startPos[1];
        int x1 = homePos[0], y1 = homePos[1];

        // 起点的代价不计入，先减去
        int ans = -rowCosts[x0] - colCosts[y0];

        // 累加代价（包含起点）
        ans += reduce(rowCosts.begin() + min(x0, x1), rowCosts.begin() + max(x0, x1) + 1, 0);
        ans += reduce(colCosts.begin() + min(y0, y1), colCosts.begin() + max(y0, y1) + 1, 0);

        return ans;
    }
};
