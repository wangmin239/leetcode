class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        
        /* build the adjacent relations */
        for (const auto& edge : edges) {
            adj[edge.front()].push_back(edge.back());
            adj[edge.back()].push_back(edge.front());
        }
        
        /* get the number of parent node's children */
        function<int(int, int&, int)> dfs = [&](int node, int& ans, int parent) {
            auto childrens = adj[node];
            bool isFirst = true;
            bool isEqual = true;
            int total = 0;
            int size;

            for (int child : childrens) {
                if (child == parent) {
                    continue;
                }
                int subTreeSize = dfs(child, ans, node);
                if (isFirst == true) {
                    size = subTreeSize;
                    isFirst = false;
                } else if (size != subTreeSize) {
                    isEqual = false;
                }
                
                total += subTreeSize;
            }
            
            
            if (isEqual == true) {
                ++ans;
            }
            
            return total + 1;
        };
        
        int ans = 0;
        dfs(0, ans, -1);
        return ans;
    }
};



class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int res = 0;
        vector<vector<int>> g(n);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        function<int(int, int)> dfs = [&](int node, int parent) -> int {
            bool valid = true;
            int treeSize = 0;
            int subTreeSize = 0;

            for (int child : g[node]) {
                if (child != parent) {
                    int size = dfs(child, node);
                    if (subTreeSize == 0) {
                        subTreeSize = size;
                    } else if (size != subTreeSize) {
                        valid = false;
                    }
                    treeSize += size;
                }
            }
            if (valid) {
                res++;
            }
            return treeSize + 1;
        };

        dfs(0, -1);
        return res;
    }
};




class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        vector<bool> isVisited(n, false);
        
        /* build the adjacent relations */
        for (const auto& edge : edges) {
            adj[edge.front()].push_back(edge.back());
            adj[edge.back()].push_back(edge.front());
        }
        
        /* get the number of one node's children */
        function<int(int, vector<bool>&, int&)> dfs = [&](int curNode, vector<bool>& isVisited, int& ans) {
            auto childrens = adj[curNode];
            int size = childrens.size();
            bool noChild = true;
            int i = 0;
            int total = 0;
            
            /* Mark the curNode have accessed, in case that it is traversed again */
            isVisited[curNode] = true;
            
            while (i < size) {
                if (isVisited[childrens[i]] == false) {
                    noChild = false;
                    break;
                }
                ++i;
            }
            /* The curNode don't have any childrens */
            if (noChild == true) {
                ++ans;
                return total;
            }
            
            /* Get the total number of the first child's childrens */
            int childNum = dfs(childrens[i], isVisited, ans);
            bool isEqual = true;
            
            total += childNum + 1;
            
            while (++i < size) {
                if (isVisited[childrens[i]] == true) {
                    continue;
                }
                /* check the number of all the children's is equal */
                int nextChildNum = dfs(childrens[i], isVisited, ans);
                if (childNum != nextChildNum) {
                    isEqual = false;
                }
                total += nextChildNum + 1;
            }
            
            if (isEqual == true) {
                ++ans;
            }
            return total;
        };
        
        int ans = 0;
        dfs(0, isVisited, ans);
        return ans;
    }
};