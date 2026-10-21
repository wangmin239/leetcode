/* Official Solution 1 */
class Solution {
public:
    int minOperations(string s) {
        char mx = 'a', mn = 'z';
        int n = s.length();
        for (int i = 0; i < n; i++) {
            mx = max(mx, s[i]);
            mn = min(mn, s[i]);
        }
        if (ranges::is_sorted(s)) {
            return 0;
        }
        if (n == 2) {
            return -1;
        }
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }   
        }
        return 3;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int minOperations(string s) {
        // s 已经是升序
        if (ranges::is_sorted(s)) {
            return 0;
        }

        int n = s.size();
        // 长为 2，无法排序
        if (n == 2) {
            return -1;
        }

        auto [mn, mx] = ranges::minmax(s);

        // 如果 s[0] 是最小值，排序 [1,n-1] 即可
        // 如果 s[n-1] 是最大值，排序 [0,n-2] 即可
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // 如果 [1,n-2] 中有最小值，那么先排序 [0,n-2]，把最小值排在最前面，然后排序 [1,n-1] 即可
        // 如果 [1,n-2] 中有最大值，那么先排序 [1,n-1]，把最大值排在最后面，然后排序 [0,n-2] 即可
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // 现在只剩下一种情况：s[0] 是最大值，s[n-1] 是最小值，且 [1,n-2] 不含最小值和最大值
        // 先排序 [0,n-2]，把最大值排到 n-2
        // 然后排序 [1,n-1]，把最大值排在最后面，且最小值排在 1
        // 最后排序 [0,n-2]，把最小值排在最前面
        return 3;
    }
};
