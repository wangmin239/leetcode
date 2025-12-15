/* Original Solution 1 */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();

        for (int left = 0, right = 0; right < n; right++) {
            while (right < n && prices[left] - prices[right] == right - left) {
                ++right;
            }

            int cnt =  right - left;
            ans += 1LL * cnt * (cnt + 1) / 2;
            left = right;

            if (right == n - 1) {
                ++ans;
            }
        }


        return ans;
    }
};


/* Original solution 2 */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();

        for (int left = 0, right = 0; right < n; right++) {
            if (prices[left] - prices[right] == right - left) {
                if (right != n - 1) {
                    continue;
                }
                right = n;
            }

            int cnt = right - left;
            ans += 1LL * cnt * (cnt + 1) / 2;
            left = right;

            if (right == n - 1) {
                ++ans;
            }            
        }

        return ans;
    }
};



/* Original solution 3 */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        int cnt = 0;
        int left, right;
        for (left = 0, right = 1; right < n; right++) {
            if (prices[left] - prices[right] == right - left) {
                continue;
            }

            cnt = right - left;
            ans += 1LL * cnt * (cnt + 1) / 2;
            left = right;  
        }

        cnt = right - left;
        ans += 1LL * cnt * (cnt + 1) / 2;
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;   // 平滑下降阶段的总数，初值为 dp[0]
        int prev = 1;   // 上一个元素为结尾的平滑下降阶段的总数，初值为 dp[0]
        // 从 1 开始遍历数组，按照递推式更新 prev 以及总数 res
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i-1] - 1) {
                ++prev;    
            }
            else {
                prev = 1;
            }
            res += prev;
        }
        return res;
    }
};