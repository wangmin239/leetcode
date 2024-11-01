class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        typedef enum tagKinds {
            A = 0,
            B = 1,
            MAX = 2,
        } Kinds;
        const int states = 3;
        vector<vector<long long>> dp(states, vector<long long>(2));
        
        dp[0][A] = energyDrinkA[0];
        dp[0][B] = energyDrinkB[0];
        dp[1][A] = energyDrinkA[0] + energyDrinkA[1];
        dp[1][B] =  energyDrinkB[0] + energyDrinkB[1];
        
        long long ans = INT_MIN;
        
        for (int i = 2; i < n; i++) {
            dp[2][A] = max(dp[1][A] + energyDrinkA[i], dp[0][B] + energyDrinkA[i]);
            dp[2][B] = max(dp[1][B] + energyDrinkB[i], dp[0][A] + energyDrinkB[i]);
            ans = max(dp[2][A], dp[2][B]);
            
            /* Update the previous state machines */
            for (int j = 1; j < states; j++) {
                dp[j - 1][A] = dp[j][A];
                dp[j - 1][B] = dp[j][B];
            }
        }
        
        return ans;
    }
};



class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        typedef enum tagKinds {
            A = 0,
            B = 1,
            MAX = 2,
        } Kinds;
        vector<vector<long long>> dp(n, vector<int>(2));
        
        dp[0][A] = energyDrinkA[0];
        dp[0][B] = energyDrinkB[0];
        dp[1][A] = energyDrinkA[0] + energyDrinkA[1];
        dp[1][B] =  energyDrinkB[0] + energyDrinkB[1];
        
        long long ans = INT_MIN;
        
        for (int i = 2; i < n; i++) {
            dp[i][A] = max(dp[i - 1][A] + energyDrinkA[i], dp[i - 2][B] + energyDrinkA[i]);
            dp[i][B] = max(dp[i - 1][B] + energyDrinkB[i], dp[i - 2][A] + energyDrinkB[i]);
            ans = max(dp[i][A], dp[i][B]);
        }
        
        return ans;
    }
};


class Solution {
public:
    using ll = long long;
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<ll>> d(n + 1, vector<ll>(2, 0));
        for (int i = 1; i <= n; i++) {
            d[i][0] = d[i - 1][0] + energyDrinkA[i - 1];
            d[i][1] = d[i - 1][1] + energyDrinkB[i - 1];
            if (i >= 2) {
                d[i][0] = max(d[i][0], d[i - 2][1] + energyDrinkA[i - 1]);
                d[i][1] = max(d[i][1], d[i - 2][0] + energyDrinkB[i - 1]);
            }
        }
        return max(d[n][0], d[n][1]);
    }
};
