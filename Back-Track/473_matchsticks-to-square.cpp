class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        const int edges = 4;
        
        if (total % edges != 0) {
            return false;
        }
        
        int len = matchsticks.size();
        
        if (len < edges) {
            return false;
        }
        
        int edgeLen = total / edges;
        vector<bool> visited(len, false);
        
        sort(matchsticks.begin(), matchsticks.end());
        
        for (int i = len - 1; i >= len - edges; i--) {
            visited[i] = true;
            if ( dfs(matchsticks, visited, edgeLen - matchsticks[i]) == false) {
                return false;
            }
        }
        
        auto isValid = [](const auto& status) {
            for (const auto statu : status) {
                if (statu == false) {
                    return false;
                }
            }
            return true;
        };
        
        if (isValid(visited) == false) {
            return false;
        }
        
        return true;
            
    }
    
    bool dfs(vector<int>& matchsticks, vector<bool>& visited, int remain) {
       if (remain < 0) {
            return false;
       }
       
       if (remain == 0) {
           return true;
       }
       
       for (int i = 0; i < matchsticks.size(); i++) {
           if (visited[i] == true) {
               continue;
           }
           
           visited[i] = true;
           if (dfs(matchsticks, visited, remain - matchsticks[i]) == true) {
               return true;
           }
           visited[i] = false;
       }
       return false;
    }  
};

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        int len = totalLen / 4, n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) {
                    continue;
                }
                int s1 = s & ~(1 << k);
                if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};



class Solution {
public:
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量

        vector<int> edges(4);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};
