class Solution {
public:
    using pii = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        for (auto &point : points) {
            int x = point[0], y = point[1];
            while (!heap.empty() && x - heap.top().second > k) {
                heap.pop();
            }
            if (!heap.empty()) {
                res = max(res, x + y - heap.top().first);
            }
            heap.emplace(x - y, x);
        }
        return res;
    }
};

class Solution {
public:
    using pii = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        deque<pii> qu;
        for (auto &point : points) {
            int x = point[0], y = point[1];
            while (!qu.empty() && x - qu.front().second > k) {
                qu.pop_front();
            }
            if (!qu.empty()) {
                res = max(res, x + y + qu.front().first);
            }
            while (!qu.empty() && y - x >= qu.back().first) {
                qu.pop_back();
            }
            qu.emplace_back(y - x, x);
        }
        return res;
    }
};





class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int len = points.size();
        int ans = INT_MIN;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (abs(points[i].front() - points[j].front()) > k) {
                    break;
                }
                ans = max(ans, points[i].back() + points[j].back() +
                            abs(points[i].front() - points[j].front()));              
            }
        }
        return ans;
    }
};