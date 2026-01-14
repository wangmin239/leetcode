class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        bitset<100000> f0, f1;
        f0[0] = 1;
        for (int i = 0, j = 0; i < rewardValues.size(); i++) {
            while (j < rewardValues[i]) {
                f1[j] = f0[j];
                j++;
            }
            f0 |= f1 << rewardValues[i];
        }
        int res = 0;
        for (int i = 0; i < f0.size(); i++) {
            if (f0[i]) {
                res = i;
            }
        }
        return res;
    }
};




class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int m = rewardValues.back();
        vector<int> dp(2 * m);
        dp[0] = 1;
        for (int x : rewardValues) {
            for (int k = 2 * x - 1; k >= x; k--) {
                if (dp[k - x]) {
                    dp[k] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i]) {
                res = i;
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        const int limit = 2001;
        sort(rewardValues.begin(), rewardValues.end());
        
        vector<int> dp(limit, 0);
        dp[rewardValues[0]] = rewardValues[0];
        
        for (int i = 1; i < n; i++) {
            int score = rewardValues[i];
            for (int j = score - 1; j > 0; j--) {
                if (dp[j] < score) {
                    dp[score] = max(dp[score], dp[j] + score);
                } else {
                    int maxVal = 0;
                    for (int k = 0; k < score - j; k++) {
                        if (dp[k] < score - j) {
                            maxVal = max(dp[k], maxVal);
                        } else if (dp[k] != 0) {
                            maxVal = max(maxVal, k);
                        }
                    }
                    dp[score] = max(dp[score], maxVal + j + score);
                }
            }

        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

