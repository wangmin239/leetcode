/* Original Solution 1 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;
        auto cmpBack = [](const auto& lhs, const auto& rhs) {
            return lhs.front() == rhs.front() ? lhs.back() > rhs.back() : lhs.front() < rhs.front();
        };

        sort(intervals.begin(), intervals.end(), cmpBack);

        for (int i = 0, j = 1; j < n; j++) {
            if (intervals[j].back() <= intervals[i].back()) {
                ++cnt;
                continue;
            }
            i = j;
        }

        return n - cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = n;
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = 0; j < intervals.size(); ++j) {
                if (i != j && intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int ans = n;
        int rmax = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][1] <= rmax) {
                --ans;
            }
            else {
                rmax = max(rmax, intervals[i][1]);
            }
        }
        return ans;
    }
};
