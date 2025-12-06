/* Official Solution 1 */
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1);
        multiset<int> cnt;
        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            cnt.emplace(nums[i]);
            // 调整窗口
            while (j <= i && *cnt.rbegin() - *cnt.begin() > k) {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }
            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }
        return dp[n];
    }
};

/* Official Solution 2 */
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1);
        deque<int> minQ, maxQ;

        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            // 维护最大值队列
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[i]) {
                maxQ.pop_back();
            }
            maxQ.push_back(i);
            // 维护最小值队列
            while (!minQ.empty() && nums[minQ.back()] >= nums[i]) {
                minQ.pop_back();
            }
            minQ.push_back(i);
            // 调整窗口
            while (!maxQ.empty() && !minQ.empty() && 
                   nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (maxQ.front() == j) {
                    maxQ.pop_front();
                }
                if (minQ.front() == j) {
                    minQ.pop_front();
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return dp[n];
    }
};

