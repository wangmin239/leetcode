/* Original Solution 1 */
class Solution {
public:
    bool checkValidString(string s) {
        int len = s.length();
        
        auto dfs = [&](int index, stack<char> st, auto&& self) {
            if (index > len) {
                return false;
            }
            
            if (index == len) {
                return st.empty();
            }
            
            if (s[index] == '(') {
                st.push(s[index]);
                return self(index + 1, st, self);
            }
            
            if (s[index] == ')') {
                if (st.empty() == true) {
                    return false;
                }
                st.pop();
                return self(index + 1, st, self);
            }
            
            bool ans = self(index + 1, st, self);
            
            st.push('(');
            ans |= self(index + 1, st, self);
            
            st.pop();
            
            if (st.empty() == true) {
                return false;
            }
            st.pop();
            ans |= self(index + 1, st, self);
            return ans;
            

        };
        
        stack<char> st;
        return dfs(0, st, dfs);
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp = vector<vector<bool>>(n,vector<bool>(n,false));

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                dp[i][i] = true;
            }
        }

        for (int i = 1; i < n; i++) {
            char c1 = s[i - 1]; 
            char c2 = s[i];
            dp[i - 1][i] = (c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*');
        }

        for (int i = n - 3; i >= 0; i--) {
            char c1 = s[i];
            for (int j = i + 2; j < n; j++) {
                char c2 = s[j];
                if ((c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*')) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                for (int k = i; k < j && !dp[i][j]; k++) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
        return dp[0][n - 1];
    }
};



/* Official Solution 2 */
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftStack;
        stack<int> asteriskStack;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                leftStack.push(i);
            } else if (c == '*') {
                asteriskStack.push(i);
            } else {
                if (!leftStack.empty()) {
                    leftStack.pop();
                } else if (!asteriskStack.empty()) {
                    asteriskStack.pop();
                } else {
                    return false;
                }
            }
        }

        while (!leftStack.empty() && !asteriskStack.empty()) {
            int leftIndex = leftStack.top();
            leftStack.pop();
            int asteriskIndex = asteriskStack.top();
            asteriskStack.pop();
            if (leftIndex > asteriskIndex) {
                return false;
            }
        }
        
        return leftStack.empty();
    }
};

/* Official Solution 3 */
class Solution {
public:
    bool checkValidString(string s) {
        int minCount = 0, maxCount = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                minCount++;
                maxCount++;
            } else if (c == ')') {
                minCount = max(minCount - 1, 0);
                maxCount--;
                if (maxCount < 0) {
                    return false;
                }
            } else {
                minCount = max(minCount - 1, 0);
                maxCount++;
            }
        }
        return minCount == 0;
    }
};
