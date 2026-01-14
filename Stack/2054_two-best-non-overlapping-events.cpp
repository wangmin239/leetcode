/* Original Solution 1 */
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        int n = events.size();
        auto cmp = [](const auto& lhs, const auto& rhs) {
            if (lhs.front() < rhs.front()) {
                return true;
            }
            
            if (lhs.front() > rhs.front()) {
                return false;
            }
            
            if (lhs[1] < rhs[1]) {
                return true;
            }
            
            if (lhs[1] > rhs[1]) {
                return false;
            }
            
            return lhs.back() > rhs.back();
        };
        
        sort(events.begin(), events.end(), cmp);
        
        /* Case 1: */
        for (const auto& event : events) {
            ans = max(ans, event.back());
        }
        
        auto getMaxPos = [&](int offset, int startTime) {
            int left = offset;
            int right = n;
            
            while (left < right) {
               int mid = (left + right) / 2;
               
               if (events[mid].front() < startTime) {
                   left = mid + 1;
               } else {
                   right = mid;
               }
            }
            int maxVal = 0;
            int maxPos = left;
            while (left < n) {
                if (events[left].back() >= maxVal) {
                    maxPos = left;
                    maxVal = events[left].back();
                }
                ++left;
            }
            
            return maxPos;
        };
        
        int curPos = 0;
        for (int i = 0; i < n - 1; i++) {
            if (curPos < n && events[curPos].front() <= events[i][1]) {
                curPos = getMaxPos(i + 1, events[i][1] + 1);
            }
            if (curPos < n) {
                ans = max(ans, events[i].back() + events[curPos].back());
            }
        }
        
        return ans;
    }
};



/* Original Solution 1 */
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        int n = events.size();
        auto cmp = [](const auto& lhs, const auto& rhs) {
            if (lhs.front() < rhs.front()) {
                return true;
            }
            
            if (lhs.front() > rhs.front()) {
                return false;
            }
            
            if (lhs[1] < rhs[1]) {
                return true;
            }
            
            if (lhs[1] > rhs[1]) {
                return false;
            }
            
            return lhs.back() > rhs.back();
        };
        
        sort(events.begin(), events.end(), cmp);
        
        /* Case 1: */
        for (const auto& event : events) {
            ans = max(ans, event.back());
        }
        
        auto getMaxValue = [&](int offset, int startTime) {
            int left = offset;
            int right = n;
            
            while (left < right) {
               int mid = (left + right) / 2;
               
               if (events[mid].front() < startTime) {
                   left = mid + 1;
               } else {
                   right = mid;
               }
            }
            int maxVal = 0;
            while (left < n) {
                maxVal = max(events[left++].back(), maxVal);
            }
            
            return maxVal;
        };
        for (int i = 0; i < n - 1; i++) {
            int secondary = getMaxValue(i + 1, events[i][1] + 1);
            ans = max(ans, secondary + events[i].back());
            
        }
        
        return ans;
    }
};


/* Official Solution 1 */
struct Event {
    // 时间戳
    int ts;
    // op = 0 表示左边界，op = 1 表示右边界
    int op;
    int val;
    Event(int _ts, int _op, int _val): ts(_ts), op(_op), val(_val) {}
    bool operator< (const Event& that) const {
        return tie(ts, op) < tie(that.ts, that.op);
    }
};


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<Event> evs;
        for (const auto& event: events) {
            evs.emplace_back(event[0], 0, event[2]);
            evs.emplace_back(event[1], 1, event[2]);
        }
        sort(evs.begin(), evs.end());
        
        int ans = 0, bestFirst = 0;
        for (const auto& [ts, op, val]: evs) {
            if (op == 0) {
                ans = max(ans, val + bestFirst);
            }
            else {
                bestFirst = max(bestFirst, val);
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // 按照结束时间排序
        ranges::sort(events, {}, [](auto& e) { return e[1]; });

        // 从栈底到栈顶，结束时间递增，价值递增
        vector<pair<int, int>> st = {{0, 0}}; // 栈底哨兵
        int ans = 0;
        for (auto& e : events) {
            int start_time = e[0], value = e[2];
            // 二分查找最后一个结束时间 < start_time 的活动
            auto it = --ranges::lower_bound(st, start_time, {}, &pair<int, int>::first);
            ans = max(ans, it->second + value);
            // 遇到比栈顶更大的价值，入栈
            if (value > st.back().second) {
                st.emplace_back(e[1], value);
            }
        }
        return ans;
    }
};
