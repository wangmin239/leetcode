class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int len = nums.size();
        vector<long> preSum(len + 1, 0);
        
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        int ans = n + 1;
        queue<int> qu;
        
        for (int i = 0; i <= n; i++) {
           long curSum = preSum[i];
            while (!qu.empty() && curSum - preSum[qu.front()] >= k) {
                ans = min(ans, i - qu.front());
                qu.pop_front();
            }
            while (!qu.empty() && preSum[qu.back()] >= curSum) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};



class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> preSumArr(n + 1);
        for (int i = 0; i < n; i++) {
            preSumArr[i + 1] = preSumArr[i] + nums[i];
        }
        int res = n + 1;
        deque<int> qu;
        for (int i = 0; i <= n; i++) {
            long curSum = preSumArr[i];
            while (!qu.empty() && curSum - preSumArr[qu.front()] >= k) {
                res = min(res, i - qu.front());
                qu.pop_front();
            }
            while (!qu.empty() && preSumArr[qu.back()] >= curSum) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};

