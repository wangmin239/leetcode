/* Original Solution 1 */
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> horizontalVal(n + 1);
        vector<pair<int, int>> verticalLimit(n + 1);
        int cities = buildings.size();
        int notConvered = 0;
        const int edges = 2;
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.front() != rhs.front() ? lhs.front() < rhs.front() : lhs.back() < rhs.back();
        };

        sort(buildings.begin(), buildings.end(), cmp);


        int minVal = buildings.front().back();
        int maxVal = minVal;
        int preX = buildings.front().front();

        horizontalVal[minVal].push_back(preX);
        for (int i = 1; i < cities; i ++) {
            int x = buildings[i].front();
            int y = buildings[i].back();
            /* Get the maximum and minimum values associated with the same y-axis label. */
            if (preX != x) {
                maxVal = buildings[i - 1].back();
                verticalLimit[preX] = move(make_pair(minVal, maxVal));
                minVal = y;
                preX = x;
            }

            horizontalVal[y].push_back(x);
        }
        /* Push the coordinate of the last one pbuilding */
        verticalLimit[preX]= move(make_pair(minVal, buildings.back().back()));

        for (size_t y = 0; y < horizontalVal.size(); y++) {
            auto&& xIndexes = horizontalVal[y];
            int size = xIndexes.size();

            notConvered += size <= edges ? size : edges;
            for (int i = 1; i < size - 1; i++) {
                int x = xIndexes[i];

                if (y == verticalLimit[x].first || y == verticalLimit[x].second) {
                    notConvered += 1;
                }   
            }
        }

        return cities - notConvered;

    }
};




/* Official Solution 1 */
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> row_min(n + 1, INT_MAX), row_max(n + 1);
        vector<int> col_min(n + 1, INT_MAX), col_max(n + 1);
        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            row_min[y] = min(row_min[y], x);
            row_max[y] = max(row_max[y], x);
            col_min[x] = min(col_min[x], y);
            col_max[x] = max(col_max[x], y);
        }

        int ans = 0;
        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            if (row_min[y] < x && x < row_max[y] && col_min[x] < y && y < col_max[x]) {
                ans++;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n + 1);
        vector<int> minRow(n + 1, n + 1);
        vector<int> maxCol(n + 1);
        vector<int> minCol(n + 1, n + 1);

        for (auto &p : buildings) {
            int x = p[0], y = p[1];
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }
        
        int res = 0;
        for (auto &p : buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
                res++;
            }
        }

        return res;
    }
};
