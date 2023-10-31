class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }

        vector<int> res(n, 1);
        vector<unordered_set<int>> geneSet(n);
        function<int(int)> dfs = [&](int node) -> int {
            geneSet[node].insert(nums[node]);
            for (auto child : children[node]) {
                res[node] = max(res[node], dfs(child));
                if (geneSet[node].size() < geneSet[child].size()) {
                    geneSet[node].swap(geneSet[child]);
                }
                geneSet[node].merge(geneSet[child]);
            }
            while (geneSet[node].count(res[node]) > 0) {
                res[node]++;
            }
            return res[node];
        };
        dfs(0);
        return res;
    }
};

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }

        unordered_set<izhnt> geneSet;
        vector<int> visited(n, 0);
        function<void(int)> dfs = [&](int node) {
            if (visited[node]) {
                return;
            }
            visited[node] = 1;
            geneSet.insert(nums[node]);
            for (auto child : children[node]) {
                dfs(child);
            }
        };

        vector<int> res(n, 1);
        int iNode = 1, node = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                node = i;
                break;
            }
        }
        while (node != -1) {
            dfs(node);
            while (geneSet.count(iNode)) {
                iNode++;
            }
            res[node] = iNode;
            node = parents[node];
        }
        return res;
    }
};
