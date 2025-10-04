/* Original Solution 1 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        priority_queue<pair<int, int>> pq;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            pq.push({height[i], i});
        }

        int start = INT_MAX;
        int end = INT_MIN;
        int area = 0;

        while (pq.empty() != true) {
            auto hiTop = pq.top();

            pq.pop();
            start = min(hiTop.second, start);
            end = max(end, hiTop.second);

            int width = max(abs(start - hiTop.second), abs(end - hiTop.second));
            area = max(area, width * hiTop.first);
        }

        return area;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};
