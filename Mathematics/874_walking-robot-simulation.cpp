/* Original Solution 1 */
class Solution {
public:
    typedef enum {
        East = 0,
        North = 1,
        West = 2,
        South = 3,
        Max
    } Dirs;

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstaclePoints;
        int x = 0;
        int y = 0;
        int degree = 90;
        const int circle = 360;
        const int unitDegree = 90;
        Dirs dir = North;
        int maxDistance = 0;

        for (const auto point : obstacles) {
            obstaclePoints.emplace(point.front(), point.back());
        }

        for (int cmd : commands) {
            if (cmd == -2) {
                degree += 90;
                dir = static_cast<Dirs>((degree % circle) / unitDegree);
            } else if (cmd == -1) {
                degree -= 90;
                if (degree < 0) {
                    degree += circle;
                }
                dir = static_cast<Dirs>((degree % circle) / unitDegree);
            } else {
               while (cmd--) {
                   if (dir == North) {
                       if (obstaclePoints.count({x, y + 1})) {
                           break;
                       }
                       ++y;
                   } else if (dir == South) {
                       if (obstaclePoints.count({x, y - 1})) {
                           break;
                       }
                       --y;
                   } else if (dir == East) {
                       if (obstaclePoints.count({x + 1, y})) {
                           break;
                       }
                       ++x;
                   } else {
                       if (obstaclePoints.count({x - 1, y})) {
                           break;
                       }
                       --x;
                   }
               }
               maxDistance = max(maxDistance, x * x + y * y);
            }
        }

        return maxDistance;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int px = 0, py = 0, d = 1;
        unordered_set<int> mp;
        for (auto &obstacle : obstacles) {
            mp.emplace(obstacle[0] * 60001 + obstacle[1]);
        }
        int res = 0;
        for (int c : commands) {
            if (c < 0) {
                d += c == -1 ? 1 : -1;
                d %= 4;
                if (d < 0) {
                    d += 4;
                }
            } else {
                for (int i = 0; i < c; i++) {
                    if (mp.count((px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
                        break;
                    }
                    px += dirs[d][0];
                    py += dirs[d][1];
                    res = max(res, px * px + py * py);
                }
            }
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 上右下左（顺时针）

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstacle_set;
        obstacle_set.reserve(obstacles.size()); // 预分配空间
        constexpr int OFFSET = 3e4;
        for (auto& p : obstacles) {
            // p 是两个 16 位整数，合并成一个 32 位整数
            obstacle_set.insert((p[0] + OFFSET) << 16 | (p[1] + OFFSET));
        }

        int ans = 0, x = 0, y = 0, k = 0;
        for (int c : commands) {
            if (c < 0) {
                k = (k + c * 2 + 7) % 4; // c=-2 左转，c=-1 右转
                continue;
            }
            while (c--) {
                int nx = x + DIRS[k][0];
                int ny = y + DIRS[k][1];
                if (obstacle_set.contains((nx + OFFSET) << 16 | (ny + OFFSET))) {
                    break;
                }
                x = nx;
                y = ny;
            }
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};
