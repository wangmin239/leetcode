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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode *> roots;

        function<TreeNode *(TreeNode *, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode * {
            if (node == nullptr) {
                return nullptr;
            }
            bool deleted = to_delete_set.count(node->val) ? true : false;
            node->left = dfs(node->left, deleted);
            node->right = dfs(node->right, deleted);
            if (deleted) {
                return nullptr;
            } else {
                if (is_root) {
                    roots.emplace_back(node);
                }
                return node;
            }
        };

        dfs(root, true);
        return roots;
    }
};


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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        ans.push_back(root);
        
        for (const int value : to_delete) {
            int size = ans.size();
            vector<TreeNode*> tmp;
            for (int i = 0; i < size; i++) {
                auto parent = ans[i];
                if (parent->val == value) {
                    ans.pop_back();
                    if (parent->left != nullptr) {
                        tmp.push_back(parent->left);
                    }
                    if (parent->right != nullptr) {
                        tmp.push_back(parent->right);
                    }
                } else {
                    tmp.push_back(parent);
                    dfs(parent, value, tmp);
                } 
            }
            ans = move(tmp);
        }
        return ans;
    }
    
    void dfs(TreeNode* parent, const int value, vector<TreeNode*>& ans) {
        auto [val, left, right] = *parent;
        if (left == nullptr && right == nullptr) {
            return;
        }
        
        if (left != nullptr) {
            if (left->val == value) {
                parent->left = nullptr;
                    if (left->left != nullptr) {
                        ans.push_back(left->left);
                    }
                    if (left->right != nullptr) {
                        ans.push_back(left->right);
                    }
            } else {
                dfs(left, value, ans);
            }
        }
        if (right != nullptr) {
            if (right->val == value) {
                parent->right = nullptr;
                    if (right->left != nullptr) {
                        ans.push_back(right->left);
                    }
                    if (right->right != nullptr) {
                        ans.push_back(right->right);
                    }
            } else {
                dfs(right, value, ans);
            }
        }          
    }
};