long long maxScore(int* nums, int numsSize, int x){
   long long dp[2] = {INT_MIN, INT_MIN};
   // 一定从nums[0]开始
   dp[nums[0] % 2] = nums[0];

   // nums[i] % 2 ：nums[i]的奇偶
   // (nums[i] + 1) % 2] ： nums[i]奇偶的相反
   for(int i = 1; i< numsSize; i++) {
       dp[nums[i] % 2] = fmax(dp[nums[i] % 2], dp[(nums[i] + 1) % 2] - x) + nums[i];
   }

   return fmax(dp[0], dp[1]);
}
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long res = nums[0];
        vector<long long> dp(2, INT_MIN);
        dp[nums[0] % 2] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int parity = nums[i] % 2;
            long long cur = max(dp[parity] + nums[i], dp[1 - parity] - x + nums[i]);
            res = max(res, cur);
            dp[parity] = max(dp[parity], cur);
        }
        return res;
    }
};

#include <ranges>
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        vector v(2, LLONG_MIN + x);
        v[nums[0] & 1] = nums[0];
        for (int i : nums | views::drop(1)) {
            bool flg = i & 1;
            v[flg] = max(v[flg], v[!flg] - x) + i;
        }
        return ranges::max(v);
    }
};

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long sum = nums.front();      
        int sameId = 0;
        int size = nums.size();

        for (int i = 1; i < size; i++) {
            if (nums[i] % 2 == nums[sameId] % 2) {
                sum += nums[i];
                sameId = i;
            } else {
                long long tmp = -x;
                int j = i;
                while (j > sameId) {
                    tmp += nums[j--];
                }

                if (tmp > 0) {
                    sum += tmp;
                    sameId = i;
                }
                
            }

        }
        return sum;
    }
};