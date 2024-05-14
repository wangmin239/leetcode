class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskFreq;
        
        /* calculate the minimum rounds of the every task takes. */
        auto calcRounds = [](const int num) {
            if (num == 1) {
                return -1;
            }
            
            if (num % 3 == 0) {
                return num / 3;
            }
            
            return num / 3 + 1;     
        };
        
        /* statistic the number of every task. */
        for (int task : tasks) {
            ++taskFreq[task];
        }
        
        /* accumulate the minimum rounds of the every task. */
        int minRounds = 0;
        for (const auto [task, num] : taskFreq) {
            int taskRounds = calcRounds(num);

            if (taskRounds == -1) {
                return -1;
            }
            minRounds += taskRounds;
        }
        
        return minRounds;
    }
};



class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (int t : tasks) {
            cnt[t]++;
        }
        int res = 0;
        for (auto [_, v] : cnt) {
            if (v == 1) {
                return -1;
            } else if (v % 3 == 0) {
                res += v / 3;
            } else {
                res += v / 3 + 1;
            }
        }
        return res;
    }
};
