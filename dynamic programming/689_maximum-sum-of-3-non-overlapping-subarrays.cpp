class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxTotal = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3 - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx = i - k * 3 + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12Idx1 = maxSum1Idx;
                    maxSum12Idx2 = i - k * 2 + 1;
                }
                if (maxSum12 + sum3 > maxTotal) {
                    maxTotal = maxSum12 + sum3;
                    ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum{0};
        for(const auto& i : nums){
            sum.push_back(sum.back()+i);
        }
        // dp[i][j] till nums[j] the max sum of i*k sub array
        vector<vector<int>> dp(4, vector<int>(n+1, 0));
        for (int i = 1; i < 4; ++i){
            for (int j = i*k; j <= n; ++j){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-k]+sum[j]-sum[j-k]);
            }
        }
        //for(auto& i : dp){ for (auto& j : i)cout<<j<<"\t";cout<<endl;}
        vector<int> ans(3);
        int idx = n;
        for(int i = 2; i >= 0; --i){
            int j = idx;
            while(idx && dp[i+1][j] == dp[i+1][idx]){
                --idx;
            }
            ans[i] = idx - k + 1;
            idx -= k - 1;
        }
        return ans;
    }
};