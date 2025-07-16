/* Original Solution 1 */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        const int mod = 2;
        int sum = nums.front() % 2; 
        int len = nums.size();
        int preVal = sum;
        int cnt = 1;
        
        /* calculating the count of the format '01' or '10'. */
        for (int i = 1; i < len; i++) {
            int curVal  = nums[i] % mod;
            sum += curVal;
            if (preVal != curVal) {
                preVal = curVal;
                ++cnt;
            }
        }
        
        /* compare the numbers of the consecutive one or zero */
        int ans = max(len - sum, sum);
        ans = max(ans, cnt);
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto& pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num % 2 == pattern[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};
