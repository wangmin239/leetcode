/* Official Solution 1 */
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] - a[0] < b[1] - b[0];
        });
        int ans = 0;
        for (auto& task : tasks) {
            ans = max(ans + task[0], task[1]);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        ranges::sort(tasks, ranges:less(), [](auto& t) { return t[0] - t[1]; }); // 按照 minimum - actual 从大到小排序

        int ans = 0;
        int s = 0; // 累计耗费的能量
        for (auto& t : tasks) {
            int actual = t[0], minimum = t[1];
            // 题目要求 E0 - s >= minimum，即 E0 >= s + minimum
            // 由此可以得到 n 个关于 E0 的下界，所有下界的最大值即为答案
            ans = max(ans, s + minimum);
            s += actual;
        }
        return ans;
    }
};
