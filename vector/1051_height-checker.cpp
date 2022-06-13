class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int m = *max_element(heights.begin(), heights.end());
        vector<int> cnt(m + 1);
        for (int h: heights) {
            ++cnt[h];
        }

        int idx = 0, ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= cnt[i]; ++j) {
                if (heights[idx] != i) {
                    ++ans;
                }
                ++idx;
            }
        }
        return ans;
    }
};
s

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights(heights);
        int sum;
        
        sort(sortedHeights.begin(), sortedHeights.end(), less<int>());
        
        sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sortedHeights[i]) {
                sum++;
            }
        }
        
        return sum;
    }
};


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        priority_queue<int> pq;
        
        for (auto val : heights) {
            pq.push(val);
        }
        
        int sum = 0;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] != pq.top()) {
                sum++;
            }
            pq.pop();
        }
        return sum;
    }
};