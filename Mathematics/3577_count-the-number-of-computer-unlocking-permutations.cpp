/* Official Solution 1 */
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1'000'000'007;
        long long ans = 1;
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = ans * i % MOD;
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0]) {
            return 0;
        }

        int mod = 1000000007;
        int ans = 1;
        for (int i = 2; i < n; ++i) {
            ans = static_cast<long long>(ans) * i % mod;
        }
        return ans;
    }
};
