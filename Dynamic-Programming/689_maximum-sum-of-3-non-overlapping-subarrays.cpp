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
        vector<int> sum;
        int cur = 0;
        for(int i = 0; i < k; ++i){
            cur += nums[i];
        }
        sum.push_back(cur);
        for(int i = k; i < nums.size(); ++i){
            cur += nums[i] - nums[i - k];
            sum.push_back(cur);
        }
        int n = sum.size();
        vector<int> left(n, 0), right(n, n - 1);
        for(int i = 1; i < n; ++i){
            if(sum[i] > sum[left[i - 1]]) left[i] = i;
            else left[i] = left[i - 1];
        }
        for(int i = n - 2; i >= 0; --i){
            if(sum[i] >= sum[right[i + 1]]) right[i] = i;
            else right[i] = right[i + 1];
        }
        int mx = 0;
        vector<int> ans(3);
        for(int i = k; i < n - k; ++i){
            if(mx < sum[i] + sum[left[i - k]] + sum[right[i + k]]){
                mx = sum[i] + sum[left[i - k]] + sum[right[i + k]];
                ans = {left[i - k], i, right[i + k]};
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