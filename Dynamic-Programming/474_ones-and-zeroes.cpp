/* Official Solution 1 */
class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= length; i++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        return dp[length][m][n];
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; i++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


/* Original Solution 1 : Time Limit Exceeded*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        auto getCount = [](const string& word) -> pair<int, int> {
            int zeros = 0;
            for (char ch : word) {
                zeros += static_cast<int>(ch == '0');
            }
            
            return {zeros, static_cast<int>(word.length() - zeros)};
        };
        
        vector<pair<int, int>> zerosAndOnes;
        for (const string& word : strs) {
            zerosAndOnes.push_back(getCount(word));
        }
        
        sort(zerosAndOnes.begin(), zerosAndOnes.end());
        int ans = 0;
        
        function<int(int, int, int)> backTrace = [&](int index, int zeroCnt, int oneCnt) {
             if (index == size) {
                 return 0;
             }
             
             int ans = 0;
             for (int i = index; i < size; i++) {
                 if (zerosAndOnes[i].first > zeroCnt || zerosAndOnes[i].second > oneCnt) {
                     continue;
                 }
                 ans = max(ans, 1 + backTrace(i + 1, zeroCnt - zerosAndOnes[i].first, oneCnt - zerosAndOnes[i].second));
                 ans = max(ans, backTrace(i + 1, zeroCnt, oneCnt));
             }
             
             return ans;
        };
        
        return backTrace(0, m, n);
        
    }
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(auto& str: strs){
            int c0 = count(str.begin(), str.end(), '0'), c1 = str.size() - c0;
            for(int j = m; j >= c0; --j){
                for(int k = n; k >= c1; --k){
                    dp[j][k] = max(dp[j][k], dp[j-c0][k-c1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};