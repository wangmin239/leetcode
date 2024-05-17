class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = profit.size(), res = 0, i = 0, best = 0;
        for (int j = 0; j < n; ++j) {
            jobs.emplace_back(difficulty[j], profit[j]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int w : worker) {
            while (i < n && w >= jobs[i].first) {
                best = max(best, jobs[i].second);
                i++;
            }
            res += best;
        }
        return res;
    }
};




class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<int> ids(n);
        
        /* build a array to simulate the mapping */
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&profit](int lhs, int rhs) {return profit[lhs] > profit[rhs];});
        sort(worker.begin(), worker.end());

        int num = 0;
        int profits = 0;
        for (int i = 0; i < n; i++) {
            int id = ids[i];
            int hardness = difficulty[id];
            /* Get the difficulty of the profit */
            auto iter = lower_bound(worker.begin(), worker.end() - num, hardness);
            if (iter == worker.end() - num) {
                continue;
            }

            int getNum = worker.end() - num - iter;
            profits += getNum * profit[id];
            num += getNum;
            
            if (num == m){
                break;
            }
        }
        
        return profits;
    }
};