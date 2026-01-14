class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
        }
        sort(startIntervals.begin(), startIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
            if (it != startIntervals.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j++;
            }
            if (j < n) {
                ans[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<int> ans(size, -1);
        auto cmp = [&](const auto& elem) {
            int index = -1;
            int ans = INT_MAX;
            for (int i = 0; i < size; i++) {
                int val = intervals[i].front();
                if (val >= elem.back()) {
                    if (val < ans) {
                        ans = val;
                        index = i;
                    }
                }
            }
            return index;
        };
        
        for (int i = 0; i < size; i++) {
            ans[i] = cmp(intervals[i]);
        }
        return ans;
    }
};