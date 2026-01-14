class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= total;
        int res = -1;
        for (int i = 0; i < n; ++i) {
            if (chalk[i] > k) {
                res = i;
                break;
            }
            k -= chalk[i];
        }
        return res;
    }
};

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        if (chalk[0] > k) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k) {
                return i;
            }
        }

        k %= chalk.back();
        return upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    }
};


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        int num = chalk.size();
        
        for (int i = 0; i < num; i++) {
            if (sum + chalk[i] > k) {
                return i;
            }
            sum += chalk[i];
        }
            
        
        int remainChalk = k % sum;

        for (int i = 0; i < num; i++) {
            if (remainChalk < chalk[i]) {
                return i;
            }
            remainChalk -= chalk[i];
        }
        return 0;
    }
};