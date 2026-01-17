/* Official Solution 1 */
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int max_side = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            auto& b1 = bottomLeft[i];
            auto& t1 = topRight[i];
            for (int j = 0; j < i; j++) {
                auto& b2 = bottomLeft[j];
                auto& t2 = topRight[j];
                int width = min(t1[0], t2[0]) - max(b1[0], b2[0]);
                int height = min(t1[1], t2[1]) - max(b1[1], b2[1]);
                int side = min(width, height);
                max_side = max(max_side, side);
            }
        }
        return 1LL * max_side * max_side;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int max_side = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            auto& b1 = bottomLeft[i];
            auto& t1 = topRight[i];
            if (t1[0] - b1[0] <= max_side || t1[1] - b1[1] <= max_side) {
                continue; // 最优性剪枝：max_side 不可能变大
            }
            for (int j = 0; j < i; j++) {
                auto& b2 = bottomLeft[j];
                auto& t2 = topRight[j];
                int width = min(t1[0], t2[0]) - max(b1[0], b2[0]); // 右上横坐标 - 左下横坐标
                int height = min(t1[1], t2[1]) - max(b1[1], b2[1]); // 右上纵坐标 - 左下纵坐标
                int side = min(width, height);
                max_side = max(max_side, side);
            }
        }
        return 1LL * max_side * max_side;
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = min(topRight[i][0], topRight[j][0]) -
                        max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) -
                        max(bottomLeft[i][1], bottomLeft[j][1]);

                maxSide = max(maxSide, min(w, h));
            }
        }

        return 1LL * maxSide * maxSide;
    }
};
