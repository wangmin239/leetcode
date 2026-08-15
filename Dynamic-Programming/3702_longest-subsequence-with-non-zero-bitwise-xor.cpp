/* Original Solution 1 */
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        auto dfs = [&](int pos, int xOr, int cnt, auto&& self) {
            if (pos == n) {
                return xOr ? cnt : 0;
            }
            

            
            int selectCnt = self(pos + 1, xOr ^ nums[pos], cnt + 1, self);
            
            int notSelect = self(pos + 1, xOr, cnt, self);

            return max(selectCnt, notSelect);
        };
        
        return dfs(0, 0, 0, dfs);
    }
};



/* Original Solution 2 */
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        
        auto dfs = [&](int pos, int xOr, int cnt, auto&& self) {
            if (pos == n) {
                return xOr ? cnt : 0;
            }
            
            if (memo[pos + 1][1] == -1) {
                memo[pos + 1][1] = self(pos + 1, xOr ^ nums[pos], cnt + 1, self);
            }
            
            if (memo[pos + 1][0] == -1) {
                memo[pos + 1][0] = self(pos + 1, xOr, cnt, self);
            }

            memo[pos][1] = max(memo[pos + 1][0], memo[pos + 1][1]);
 
            return memo[pos][1];
        };
        
        dfs(0, 0, 0, dfs);
        
        return memo[0][1];
    }
};

/* Official Solution 1 */
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool allZero = true;

        for (int x : nums) {
            totalXor ^= x;
            if (x > 0) {
                allZero = false;
            }
        }

        if (totalXor > 0) {
            return n;
        }

        return allZero ? 0 : n - 1;
    }
};
