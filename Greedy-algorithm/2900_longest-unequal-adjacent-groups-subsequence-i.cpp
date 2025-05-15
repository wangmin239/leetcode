
/* Original Solution */
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int> sequence;
        
        
        /* get the Maximum length */
        auto getMax = [&groups, n](int index, vector<int>& sequence) {
            int left = index;
            int right = index;
            
            sequence.push_back(left);
            while (++right < n) {
                if (groups[left] != groups[right]) {
                    left = right;
                    sequence.push_back(left);
                }
            }
            return ;
        };
        
        getMax(0, sequence);
        
        auto buildStr = [&words](vector<int>& sequence) {
            vector<string> strVec;
            for (int index : sequence) {
                strVec.push_back(words[index]);
            }
            return strVec;
        };

        
        return buildStr(sequence);
        
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxLen = 1, endIndex = 0;

        for (int i = 1; i < n; i++) {
            int bestLen = 1;
            int bestPrev = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && dp[j] + 1 > bestLen) {
                    bestLen = dp[j] + 1;
                    bestPrev = j;
                }
            }
            dp[i] = bestLen;
            prev[i] = bestPrev;
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        vector<string> res;
        for (int i = endIndex; i != -1; i = prev[i]) {
            res.emplace_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
