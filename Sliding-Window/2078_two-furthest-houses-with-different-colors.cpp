/* Original Solution 1 */
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int distance = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (colors[i] != colors[j]) {
                    distance = max(, j - i);
                    break;
                }
            }
        }

        return 
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int c = colors[0];
        if (c != colors[n - 1]) {
            return n - 1;
        }

        // 找最右边的颜色不等于 c 的房子
        // 题目保证至少有两栋颜色不同的房子
        int r = n - 2;
        while (colors[r] == c) {
            r--;
        }

        // 找最左边的颜色不等于 c 的房子
        int l = 1;
        while (colors[l] == c) {
            l++;
        }

        return max(r, n - 1 - l);
    }
};
