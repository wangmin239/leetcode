/* Original Solution 1 */
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        size_t len = s1.length();
        const int chCnt = 26;

        unordered_map<char, vector<char>> chMap;
        
        for (size_t i = 0; i < len; i++) {
           chMap[s1[i]].push_back(s2[i]);
           if (s1[i] != s2[i]) {
              chMap[s2[i]].push_back(s1[i]);
           }              
        }
        
        vector<bool> visited(chCnt, false);
        
        auto dfs = [&](const char ch, vector<bool>& visited, auto& innerDfs, vector<char>& curChArr) {
            int index = static_cast<int>(ch - 'a');
            
            if (visited[index] == true) {
                return;
            }
            
            visited[index] = true;
            for (const char nextCh : chMap[ch]) {
                curChArr.push_back(nextCh);
                innerDfs(nextCh, visited, innerDfs, curChArr);  
            }
            return;
        };
        
        vector<vector<char>> chChain;
        for (auto& [ch, chVec] : chMap) {
            int index = static_cast<int>(ch - 'a');
            if (visited[index] == true) {
                continue;
            }
            vector<char> curChArr;
            curChArr.push_back(ch);
            dfs(ch, visited, dfs, curChArr);
            chChain.push_back(curChArr);
        }
        
        unordered_map<char, char> minCh;
        for (auto& vec : chChain) {
            char min = *min_element(vec.begin(), vec.end());
            for (char ch : vec) {
                minCh[ch] = min;
            }
        }
        

        string ans(baseStr);
        for (size_t i = 0; i < baseStr.length(); i++) {
            char ch = baseStr[i];
            if (minCh.count(ch)) {
                ans[i] = minCh[ch];
            }
        }
        
        return ans;
    }
};


/* Official Solution 1 */
class UnionFind {
    vector<int> f;
    int n;
public:
    UnionFind(int n) : n(n) {
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }
    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if(x > y) {
            swap(x, y);
        }
        // 总是让字典序更小的作为集合代表字符
        f[y] = x;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for(int i = 0; i < s1.size(); i++) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            uf.unite(x, y);
        }
        for(int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = 'a' + uf.find(baseStr[i] - 'a');
        }
        return baseStr;
    }
};
