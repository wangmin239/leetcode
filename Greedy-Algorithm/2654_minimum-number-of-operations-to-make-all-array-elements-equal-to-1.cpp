/* Official Solution 2 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), gcd_all = 0, cnt1 = 0;
        for (int x : nums) {
            gcd_all = gcd(gcd_all, x);
            cnt1 += x == 1;
        }
        if (gcd_all > 1) return -1;
        if (cnt1) return n - cnt1;

        int min_size = n;
        vector<pair<int, int>> g; // {GCD，相同 GCD 闭区间的右端点}
        for (int i = 0; i < n; i++) {
            g.emplace_back(nums[i], i);
            // 原地去重，因为相同的 GCD 都相邻在一起
            int j = 0;
            for (auto& p : g) {
                p.first = gcd(p.first, nums[i]);
                if (g[j].first == p.first)
                    g[j].second = p.second;
                else g[++j] = move(p);
            }
            g.resize(j + 1);
            if (g[0].first == 1)
                // 这里本来是 i-g[0].second+1，把 +1 提出来合并到 return 中
                min_size = min(min_size, i - g[0].second);
        }
        return min_size + n - 1;
    }
};




/* Official Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0;
        int g = 0;
        for (int x : nums) {
            if (x == 1) {
                num1++;
            }
            g = gcd(g, x);
        }
        if (num1 > 0) {
            return n - num1;
        }
        if (g > 1) {
            return -1;
        }

        int min_len = n;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }
        return min_len + n - 2;
    }
};
