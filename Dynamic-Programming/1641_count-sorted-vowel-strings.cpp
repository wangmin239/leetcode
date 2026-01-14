class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};


class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};
