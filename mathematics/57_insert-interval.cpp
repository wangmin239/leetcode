class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        auto iter = intervals.begin();
        bool isInsert = false;

        while (iter != intervals.end()) {
            if (iter->back() < newInterval.front()) {
                ans.push_back(*iter);
                ++iter;
            } else {
                if (newInterval.back() < iter->front()) {
                    ans.push_back(newInterval);
                    ans.push_back(*iter);
                } else {
                    int left = min(iter->front(), newInterval.front());
                    int right = max(iter->back(), newInterval.back());
                    ans.push_back({left, right});
                }
                ++iter;
                isInsert = true;
                break;
            }
        }
        
        for (; iter != intervals.end(); ++iter) {
            if (iter->front() > ans.back().back()) {
                ans.push_back(*iter);
                continue;
            }
            ans.back().front() = min(iter->front(), ans.back().front());
            ans.back().back() = max(iter->back(), ans.back().back());
        }
        
        if (isInsert == false) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
