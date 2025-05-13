/* Original Solution */
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int len = s.length();
        const int num = 26;
        int arr[num] = {0};
        const constexpr int mod = 1e9 + 7;

        
        fill_n(arr, num, 0);
        for (char ch : s) {
            int index = static_cast<int>(ch - 'a');
            ++arr[index];
        }
        vector<vector<long long >> memo(num, vector<long long>(t, -1));
        
        function<long long(const char, int)> dfs = [&](const char ch, int turns) {
            int convert2z = static_cast<int>('z' - ch);
            int index = static_cast<int>(ch - 'a');
            
            if (turns <= convert2z) {
                memo[index][turns] = 0LL;
                return 0LL;
            }
            
            if (memo[index][turns] != -1) {
                return memo[index][turns];
            }
            
            memo[index][turns] =  (dfs('a', turns - convert2z - 1) + dfs('b', turns - convert2z - 1) + 1) % mod;
            return memo[index][turns];
            
        };
        
        for (int i = 0; i < num; i++) {
            if (arr[i] < 1) {
                continue;
            }
            
            char ch = static_cast<char>('a' + i);
            int cnt = arr[i];
            len = static_cast<int>((1LL * cnt * dfs(ch, t) + len) % mod);
        }
        
        return len;        
    }
};


/* Official Solution 1 */
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char ch: s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};

/* Official Solution 2 */
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
          const int MOD = 1000000007;
          std::vector<int64_t> cnt(26);
          for (auto c : s) {
            cnt[c - 'a']++;
          }  

          for (int i = 0, k = 25; i < t; i++) {
              cnt[(k + 1) % 26] = (cnt[(k + 1) % 26] + cnt[k]) % MOD;
              k = (k - 1 + 26) % 26;
          }

          return accumulate(cnt.begin(), cnt.end(), 0LL) % MOD;
    }
};


