/* Official Solution 1 */
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> robotDist;
        for (int i = 0; i < n; i++) {
            robotDist.push_back({robots[i], distance[i]});
        }
        sort(robotDist.begin(), robotDist.end());
        sort(walls.begin(), walls.end());

        int m = walls.size();
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        // DP 变量：只保存前一个值
        int prevLeft = 0, prevRight = 0, prevNum = 0;
        int subLeft = 0, subRight = 0;

        for (int i = 0; i < n; i++) {
            int robotPos = robotDist[i].first;
            int robotDistVal = robotDist[i].second;

            // rightPtr 找到第一个 > robotPos 的位置 (对应 upper_bound)
            while (rightPtr < m && walls[rightPtr] <= robotPos) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            // curPtr 找到第一个 >= robotPos 的位置 (对应 lower_bound)
            while (curPtr < m && walls[curPtr] < robotPos) {
                curPtr++;
            }
            int pos2 = curPtr;

            // leftPtr 找到第一个 >= 左边界的墙
            int leftBound = (i >= 1) ? max(robotPos - robotDistVal, robotDist[i - 1].first + 1) : robotPos - robotDistVal;
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            int currentLeft = pos1 - leftPos;

            // 计算右边可达的墙的数量
            int rightBound = (i < n - 1) ? min(robotPos + robotDistVal, robotDist[i + 1].first - 1) : robotPos + robotDistVal;
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            int currentRight = rightPos - pos2;

            // robotPtr 找到上一个机器人的位置
            int currentNum = 0;
            if (i > 0) {
                while (robotPtr < m && walls[robotPtr] < robotDist[i - 1].first) {
                    robotPtr++;
                }
                int pos3 = robotPtr;
                currentNum = pos1 - pos3;
            }

            if (i == 0) {
                subLeft = currentLeft;
                subRight = currentRight;
            } else {
                int newsubLeft = max(subLeft + currentLeft, subRight - prevRight + min(currentLeft + prevRight, currentNum));
                int newsubRight = max(subLeft + currentRight, subRight + currentRight);
                subLeft = newsubLeft;
                subRight = newsubRight;
            }

            prevLeft = currentLeft;
            prevRight = currentRight;
            prevNum = currentNum;
        }

        return max(subLeft, subRight);
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size(), m = walls.size();
        struct Pair { int x, d; };
        vector<Pair> a(n + 2);
        for (int i = 0; i < n; i++) {
            a[i] = {robots[i], distance[i]};
        }
        a[n + 1].x = INT_MAX;
        ranges::sort(a, {}, &Pair::x);
        ranges::sort(walls);

        int f0 = 0, f1 = 0, left = 0, cur = 0, right0 = 0, right1 = 0;
        for (int i = 1; i <= n; i++) {
            auto [x, d] = a[i];

            // 往左射，墙的坐标范围为 [left_x, x]
            int left_x = max(x - d, a[i - 1].x + 1); // +1 表示不能射到左边那个机器人
            while (left < m && walls[left] < left_x) {
                left++;
            }
            while (cur < m && walls[cur] < x) {
                cur++;
            }
            int cur1 = cur;
            if (cur < m && walls[cur] == x) {
                cur++;
            }
            int left_res = f0 + cur - left; // 下标在 [left, cur-1] 中的墙都能摧毁

            // 往右射，右边那个机器人往左射，墙的坐标范围为 [x, right_x]
            auto [x2, d2] = a[i + 1];
            int right_x = min(x + d, x2 - d2 - 1); // -1 表示不能射到右边那个机器人
            while (right0 < m && walls[right0] <= right_x) {
                right0++;
            }
            f0 = max(left_res, f1 + right0 - cur1); // 下标在 [cur1, right0-1] 中的墙都能摧毁

            // 往右射，右边那个机器人往右射，墙的坐标范围为 [x, right_x]
            right_x = min(x + d, x2 - 1); // -1 表示不能射到右边那个机器人
            while (right1 < m && walls[right1] <= right_x) {
                right1++;
            }
            f1 = max(left_res, f1 + right1 - cur1); // 下标在 [cur1, right1-1] 中的墙都能摧毁
        }
        return f1;
    }
};
