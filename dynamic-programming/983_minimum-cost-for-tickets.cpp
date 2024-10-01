class Solution {
    unordered_set<int> dayset;
    vector<int> costs;
    int memo[366] = {0};

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        for (int d: days) {
            dayset.insert(d);
        }
        memset(memo, -1, sizeof(memo));
        return dp(1);
    }

    int dp(int i) {
        if (i > 365) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        if (dayset.count(i)) {
            memo[i] = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
        } else {
            memo[i] = dp(i + 1);
        }
        return memo[i];
    }
};



class Solution {
private:
    vector<int> days, costs;
    vector<int> memo;
    int durations[3] = {1, 7, 30};
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        memo.assign(days.size(), -1);
        return dp(0);
    }

    int dp(int i) {
        if (i >= days.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; ++k) {
            while (j < days.size() && days[j] < days[i] + durations[k]) {
                ++j;
            }
            memo[i] = min(memo[i], dp(j) + costs[k]);
        }
        return memo[i];
    }
};
