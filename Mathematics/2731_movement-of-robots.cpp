class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                pos[i] = (long long) nums[i] - d;
            } else {
                pos[i] = (long long) nums[i] + d;
            }
        }
        sort(pos.begin(), pos.end());
        long long res = 0;
        for (int i = 1; i < n; i++) {
            res += 1ll * (pos[i] - pos[i - 1]) * i % mod * (n - i) % mod;
            res %= mod;
        }
        return res;
    }
};


class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<int> seq(n);

        /* sort the positions of the robots */
        iota(seq.begin(), seq.end(), 0);
        auto cmp = [nums](int i, int j) { return nums[i] < nums[j]; };
        sort(seq.begin(), seq.end(), cmp);

        /* check if there is no confliction */
        auto check = [n](string& s) {
            for (int i = 1; i < n; i++) {
                if (s[i] != s[i - 1]) {
                    return false;
                }
            }
            return true;
        };
        /* calculating the sum distance */
        auto distance = [n, &seq](const vector<int>& nums) {
            int sum = 0;
            const int mod = 1e9 + 7;
            for (int i = 0; i < n - 1; i++) {
                int pos = nums[seq[i]];
                for (int j = i + 1; j < n; j++) {
                    sum += nums[seq[j]] - pos;
                    sum %= mod;
                }
            }
            return sum;
        };

        for (int time = 0; time < d; time++) {
            if (check(s) == true) {
                return distance(nums);
            }

            for (int i = 0;  i < n; i++) {
               int j = seq[i];
               if (s[j] == 'L') {
                   nums[j] -= 1;
               } else {
                   nums[j] += 1;
               }
               if (i > 0) {
                   int k = seq[i - 1];
                   if (nums[k] > nums[j] || (nums[k] == nums[j] && s[k] =='R' && s[j] == 'L')) {
                       s[k] = 'L';
                       s[j] = 'R';
                   }
                   if (nums[k] > nums[j]) {
                       --nums[k];
                       ++nums[j];
                       if (i > 1) {
                           int l = seq[i - 2];
                           if (nums[k] == nums[l] && s[k] =='L' && s[l] == 'R') {
                            s[k] = 'R';
                            s[l] = 'L';  
                           }
                       }
                   }                   
                }
            }
        }

        return distance(nums);

    }
};
