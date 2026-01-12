/* Original Solution 1 */
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        auto getMinTime = [](const vector<int>& lhs, const vector<int>& rhs) {
            int x1 = lhs.front();
            int y1 = lhs.back();
            int x2 = rhs.front();
            int y2 = rhs.back();

            if (x1 == x2) {
                return abs(y1 - y2);
            }

            if (y1 == y2) {
                return abs(x1 - x2);
            }

            int moveX = y2 + x1 - y1;
            int moveY = x2 + y1 - x1;
            int minTime = INT_MAX;
            int t1 = abs(moveX - x2) + abs(y2 - y1);
            int t2 = abs(moveY - y2) + abs(x2 - x1);
            
            minTime = min(t1, t2);
            moveX = x1 + y1 - y2;
            moveY = x1 + y1 - x2;
            
            t1 = abs(moveX - x2) + abs(y2 - y1);
            t2 = abs(moveY - y2) + abs(x2 - x1);
            minTime = min(minTime, t1);
            return min(minTime, t2);
        };

        int totalTime = 0;
        int n = points.size();

        for (int i = 1; i < n; i++) {
            totalTime += getMinTime(points[i - 1], points[i]);
        }

        return totalTime;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x0 = points[0][0], x1 = points[0][1];
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            int y0 = points[i][0], y1 = points[i][1];
            ans += max(abs(x0 - y0), abs(x1 - y1));
            x0 = y0;
            x1 = y1;
        }
        return ans;
    }
};
