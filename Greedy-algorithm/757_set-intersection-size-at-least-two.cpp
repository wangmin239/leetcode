/* Official Solution  1 */
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });  // 左边界升序，若相同，右边界降序
        int res = 2, ls = intervals.back()[0], rs = ls + 1;
        for(int i = intervals.size() - 2; i >= 0; i--){
            if(intervals[i][1] >= rs){  // 有两个及以上的交点
                continue;
            }else if(intervals[i][1] < ls){  // 没有交点
                ls = intervals[i][0];
                rs = intervals[i][0] + 1;
                res += 2;
            }else{  // 一个交点
                rs = ls;
                ls = intervals[i][0];
                res++;
            }
        }
        return res;
    }
};

/* Official Solution  2 */
class Solution {
public:
    void help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num) {
        for (int i = pos; i >= 0; i--) {
            if (intervals[i][1] < num) {
                break;
            }
            temp[i].push_back(num);
        }
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        int m = 2;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> temp(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = intervals[i][0], k = temp[i].size(); k < m; j++, k++) {
                res++;
                help(intervals, temp, i - 1, j);
            }
        }
        return res;
    }
};
