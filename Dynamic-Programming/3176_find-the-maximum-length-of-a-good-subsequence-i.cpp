class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int len = nums.size();
        vector<vector<int>> dp;
        dp.resize(len, vector<int>(51, -1));

        for (int i = 0; i < len; i++) {
            dp[i][0] = 1;
            for (int l = 0; l <= k; l++) {
                for (int j = 0; j < i; j++) {
                    int add = (nums[i] != nums[j]);
                    if (l - add >= 0 && dp[j][l - add] != -1) {
                        dp[i][l] = max(dp[i][l], dp[j][l - add] + 1);
                    }
                }
                ans = max(ans, dp[i][l]);
            }
        }

        return ans;
    }
};


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, vector<int>> dp;
        vector<int> zd(k + 1, 0);

        for (int i = 0; i < len; i++) {
            int v = nums[i];
            if (!dp.count(v)) {
                dp[v] = vector<int>(k + 1, 0);
            }

            auto& tmp = dp[v];
            for (int j = 0; j <= k; j++) {
                tmp[j] = tmp[j] + 1;
                if (j > 0) {
                    tmp[j] = max(tmp[j], zd[j - 1] + 1);
                }
            }
            for (int j = 0; j <= k; j++) {
                zd[j] = max(zd[j], tmp[j]);
            }
        }
        return zd[k];
    }
};
