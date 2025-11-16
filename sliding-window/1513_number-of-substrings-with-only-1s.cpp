/* Original Solution 1 */
class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        const int mod = 1e9 + 7;
        long long sum = 0;

        for (int left = 0; left < n; left++) {
            if (s[left] == '0') {
                continue;
            }
            
            int right = left;
            while (right < n) {
                if (s[right] == '0') {
                    break;
                }
                ++right;
                sum += right - left;
                sum %= mod;
            }
            sum += right - left;
            sum %= mod;
            left = right;
        }
        
        return sum;
    }
};



/* Original Solution 1 */
class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        const int mod = 1e9 + 7;
        size_t sum = 0;

        for (int left = 0; left < n; left++) {
            if (s[left] == '0') {
                continue;
            }
            
            int right = left;
            while (right < n) {
                if (s[right] == '0') {
                    break;
                }
                sum += right - left;
                sum %= mod;
                ++right;
            }
            sum += right - left;
            sum %= mod;
            left = right;
        }
        
        return sum;
    }
};


/* Official Solution 1 */
class Solution {
public:
    static constexpr int P = int(1E9) + 7;
    
    int numSub(string s) {
        int p = 0;
        long long ans = 0;
        while (p < s.size()) {
            if (s[p] == '0') {
                ++p;
                continue;
            }
            int cnt = 0;
            while (p < s.size() && s[p] == '1') {
                ++cnt;
                ++p;
            }
            ans = ans + (1LL + (long long)cnt) * cnt / 2;
            ans = ans % P;
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int numSub(string s) {
        constexpr int MOD = 1'000'000'007;
        long long ans = 0;
        int last0 = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                last0 = i; // 记录上个 0 的位置
            } else {
                ans += i - last0; // 右端点为 i 的全 1 子串个数
            }
        }
        return ans % MOD;
    }
};
