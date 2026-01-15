/* Original Solution 1 */
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxArea = 1;
        auto getSegment = [](const vector<int>& bars) {
            int size = bars.size();
            int left, right;
            int maxDiff = 1;
            for (left = 0, right = 0; right < size; right++) {
                if (bars[right] - bars[left] != right - left) {
                    maxDiff = max(maxDiff, right - left + 1);
                    left = right;
                }
            }

            maxDiff = max(maxDiff, right - left + 1);
            return maxDiff;
        }; 

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        auto width = getSegment(hBars);
        width = min(width, getSegment(vBars));


        return width * width;
    }
};


/* Official Solution 1 */
class Solution {
    // 返回 a 排序后的最长连续递增子数组的长度
    int f(vector<int>& a) {
        ranges::sort(a);
        int mx = 1, cnt = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1] + 1) {
                cnt++;
                mx = max(mx, cnt);
            } else {
                cnt = 1; // 重新计数
            }
        }
        return mx;
    }

public:
    int maximizeSquareHoleArea(int, int, vector<int>& hBars, vector<int>& vBars) {
        int side = min(f(hBars), f(vBars)) + 1;
        return side * side;
    }
};

/* Official Solution 2 */
class Solution {
    // 128. 最长连续序列
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // 把 nums 转成哈希集合
        int ans = 0;
        for (int x : st) { // 遍历哈希集合
            if (st.contains(x - 1)) { // 如果 x 不是序列的起点，直接跳过
                continue;
            }
            // x 是序列的起点
            int y = x + 1;
            while (st.contains(y)) { // 不断查找下一个数是否在哈希集合中
                y++;
            }
            // 循环结束后，y-1 是最后一个在哈希集合中的数
            ans = max(ans, y - x); // 从 x 到 y-1 一共 y-x 个数
        }
        return ans;
    }

public:
    int maximizeSquareHoleArea(int, int, vector<int>& hBars, vector<int>& vBars) {
        int side = min(longestConsecutive(hBars), longestConsecutive(vBars)) + 1;
        return side * side;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hmax = 1, vmax = 1;
        int hcur = 1, vcur = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }
            hmax = max(hmax, hcur);
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = max(vmax, vcur);
        }
        int side = min(hmax, vmax) + 1;
        return side * side;
    }
};

