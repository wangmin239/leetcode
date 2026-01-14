/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> treeMap;
        queue<pair<TreeNode*, int>> que;
        int row = 0;

        if (root != nullptr) {
            que.push(make_pair(root, 0));
        }
        
        while (que.empty() == false) {

            for (int size = que.size(); size > 0; size--) {
                auto parent = que.front();
                auto [val, left, right] = *(parent.first);
                
                que.pop();
                /* firstly, ascend order by column index, then by row index */
                if (treeMap.count(parent.second) > 0) {
                    treeMap[parent.second][row].push_back(val);
                } else {
                    treeMap.emplace(parent.second, map<int,vector<int>> {{row, vector<int>{val}}});
                }
                /* push children nodes into queue */
                if (left != nullptr) {
                    que.push(make_pair(left, parent.second - 1));
                }
                
                if (right != nullptr) {
                    que.push(make_pair(right, parent.second + 1));
                }  
            }
            row++;
        }
        
        for (auto& [col, rowMap] : treeMap) {
            ans.emplace_back();
            for (auto& [row, vec] : rowMap) {
                sort(vec.begin(), vec.end());
                for (auto val : vec) {
                    ans.back().push_back(val);
                }
            }
        }
        return ans;
    }
};





class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int row, int col) {
            if (!node) {
                return;
            }
            nodes.emplace_back(col, row, node->val);
            dfs(node->left, row + 1, col - 1);
            dfs(node->right, row + 1, col + 1);
        };

        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int lastcol = INT_MIN;
        for (const auto& [col, row, value]: nodes) {
            if (col != lastcol) {
                lastcol = col;
                ans.emplace_back();
            }
            ans.back().push_back(value);
        }
        return ans;
    }
};
