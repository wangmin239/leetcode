/* Official Solution 1 */
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;
        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<int, vector<float>> midToSlope;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                float k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }
        for (auto& [_, sti] : slopeToIntercept) {
            if (sti.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float b : sti) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans += sum * count;
                sum += count;
            }
        }
        for (auto& [_, mts] : midToSlope) {
            if (mts.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float k : mts) {
                cnt[k]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans -= sum * count;
                sum += count;
            }
        }
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<double, vector<double>> groups; // 斜率 -> [截距]
        unordered_map<int, vector<double>> groups2; // 中点 -> [斜率]

        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            for (int j = 0; j < i; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dy = y - y2;
                int dx = x - x2;
                double k = dx ? 1.0 * dy / dx : DBL_MAX;
                double b = dx ? 1.0 * (y * dx - x * dy) / dx : x;
                groups[k].push_back(b);
                int mid = (x + x2 + 2000) << 16 | (y + y2 + 2000); // 把二维坐标压缩成一个 int
                groups2[mid].push_back(k);
            }
        }

        int ans = 0;
        for (auto& [_, g] : groups) {
            if (g.size() == 1) {
                continue;
            }
            // 对于本题的数据，map 比哈希表快
            map<double, int> cnt;
            for (double b : g) {
                cnt[b]++;
            }
            int s = 0;
            for (auto& [_, c] : cnt) {
                ans += s * c;
                s += c;
            }
        }

        for (auto& [_, g] : groups2) {
            if (g.size() == 1) {
                continue;
            }
            map<double, int> cnt;
            for (double k : g) {
                cnt[k]++;
            }
            int s = 0;
            for (auto& [_, c] : cnt) {
                ans -= s * c; // 平行四边形会统计两次，减去多统计的一次
                s += c;
            }
        }

        return ans;
    }
};

