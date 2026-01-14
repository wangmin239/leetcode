class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();

        for (const int roll : rolls) {
            sum += roll;
        }
        
        int remain = mean *  (n + m) - sum;
        const int maxRoll = 6;
        /* invalid case */
        if (remain < n || remain  > n * maxRoll) {
            return {};
        }
        
        if (remain == n) {
            return vector<int>(n, 1);
        }
        if (remain == n * maxRoll) {
            return vector<int>(n, 6);
        }
        
        vector<int> ans(n, 6);
        for (int i = 0; i < n; i++) {
            for(int roll = 1; roll < 7; roll++) {
                if (remain >= roll && remain <= (n - i - 1) * maxRoll + roll) { 
                    ans[i] = roll;
                    remain -= roll;
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        int missingSum = sum;
        for (int & roll : rolls) {
            missingSum -= roll;
        }
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        int quotient = missingSum / n, remainder = missingSum % n;
        vector<int> missing(n);
        for (int i = 0; i < n; i++) {
            missing[i] = quotient + (i < remainder ? 1 : 0);
        }
        return missing;
    }
};




class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();

        for (const int roll : rolls) {
            sum += roll;
        }
        
        int remain = mean *  (n + m) - sum;
        const int maxRoll = 6;
        /* invalid case */
        if (remain <= 0 || remain  > n * maxRoll) {
            return {};
        }
        
        vector<int> ans;
        vector<vector<int>> finalAns;
        dfs(ans, n, remain, finalAns);
        return finalAns.front();
    }
    
    void dfs(vector<int>& ans, int n, int remain, vector<vector<int>>& final) {
        if (n < 0) {
            return ;
        }
        
        if (n == 0 && remain == 0) {
            final.push_back(ans);
            return ;
        }
        
        for (int roll = 1; roll < 7; roll++) {
            if (remain < roll || remain > (n - 1) * 6 + roll) {
                continue;
            }
            ans.push_back(roll);
            dfs(ans, n - 1, remain - roll, final);
            if (final.empty() == false) {
                break;
            }
            ans.pop_back();
        }
        return ;
    }
};