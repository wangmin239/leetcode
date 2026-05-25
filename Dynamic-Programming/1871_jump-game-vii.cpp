
/* Original Solution 1 */
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.length();
        vector<int> memo(len, -1);
        auto dfs = [&](int i, auto&& self) {
            if (i == len - 1) {
                return s[i] == '0';
            }

            if (memo[i] != -1) {
                return static_cast<bool>(memo[i]);
            }

            bool ans = false;

            for (int j = i + minJump; j <= min(i + maxJump, len - 1); j++) {
                if (s[j] == '1') {
                    continue;
                }

                ans |= self(j, self);
            }

            memo[i] = static_cast<int>(ans);
            return ans;
        };

        return dfs(0, dfs);
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), pre(n);
        f[0] = 1;
        // 由于我们从 i=minJump 开始动态规划，因此需要将 [0,minJump) 这部分的前缀和预处理出来
        for (int i = 0; i < minJump; ++i) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; ++i) {
            int left = i - maxJump, right = i - minJump;
            if (s[i] == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                f[i] = (total != 0);
            }
            pre[i] = pre[i - 1] + f[i];
        }
        return f[n - 1];
    }
};


/* Official Solution 2 */
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int8_t> can_reaches(n);
        can_reaches[0] = true;

        int j = 1;
        for (int i = 0; i < n && j < n; i++) {
            if (s[i] == '0' && can_reaches[i]) {
                // 注意 j 只会增大，不会减小，所以总体时间复杂度是 O(n)
                for (j = max(j, i + minJump); j <= min(i + maxJump, n - 1); j++) {
                    can_reaches[j] = true; // 可以跳到 j
                }
            }
        }

        return s[n - 1] == '0' && can_reaches[n - 1];
    }
};



/* Official Solution 3 */
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> diff(n + 1);

        // 一开始在起点 0，把 [0, 0] 加一
        diff[0] = 1;
        diff[1] = -1;

        int sum_d = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            sum_d += diff[i];
            // 现在 sum_d 是下标 i 的标记次数
            if (sum_d > 0 && ch == '0') { // i 可以跳到
                // [i+minJump, i+maxJump] 可以跳到
                diff[min(i + minJump, n)]++;
                diff[min(i + maxJump + 1, n)]--;
            }
        }

        return sum_d > 0 && s[n - 1] == '0'; // n-1 可以跳到
    }
};
