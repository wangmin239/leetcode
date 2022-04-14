class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxValue = 0;
        
        for (const auto& account : accounts) {
            int sum = 0;
            for (const int& val : account) {
                sum += val;
            }
            
            maxValue = max(sum, maxValue);
        }
        return maxValue;
    }
};


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for (auto &account : accounts) {
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        }
        return maxWealth;
    }
};
