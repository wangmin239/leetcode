/* Original Solution 1 */
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        auto incrCmp = [](const auto& lhs, const auto& rhs) {
            return lhs.front() != rhs.front() ? lhs.front() < rhs.front():
                    lhs.back() < rhs.back();
        };
        
        int ans = 0;
        int preEnd = 0;
        
        /* Sort the start date of each meeting in ascending order. */
        sort(meetings.begin(), meetings.end(), incrCmp);
        
        for (const auto& meeting : meetings) {
            int start = meeting.front();
            int end = meeting.back();
            
            /* In the case where two consecutive meetings do not overlap. */
            if (start > preEnd) {
                ans += start - preEnd - 1;
                preEnd = end;
            } else {
                preEnd = max(end, preEnd);
            }
        }
        /* The last meeting does not end on the given date. */
        if (days > preEnd) {
            ans += days - preEnd;
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int l = 1, r = 0;
        for (auto m : meetings) {
            if (m[0] > r) {
                days -= (r - l + 1);
                l = m[0];
            }
            r = max(r, m[1]);
        }
        days -= (r - l + 1);
        return days;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        ranges::sort(meetings); // 按照左端点从小到大排序
        int start = 1, end = 0; // 当前合并区间的左右端点
        for (auto& p : meetings) {
            if (p[0] > end) { // 不相交
                days -= end - start + 1; // 当前合并区间的长度
                start = p[0]; // 下一个合并区间的左端点
            }
            end = max(end, p[1]);
        }
        days -= end - start + 1; // 最后一个合并区间的长度
        return days;
    }
};
