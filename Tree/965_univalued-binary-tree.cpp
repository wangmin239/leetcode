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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        function<bool(const TreeNode*, const int)> dfs = [&](const TreeNode* node, const int value) {
                if (node == nullptr) {
                    return true;
                }
                
                auto [val, left, right] = *node;
                if (val != value) {
                    return false;
                }
                
                return dfs(left, value) && dfs(right, value);
        };
        
        auto [value, left, right] = *root;
        return dfs(root, value);
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        const int value = root->val;
        auto dfs = [&value](const auto* node, const auto&& treeDfs) {
                if (node == nullptr) {
                    return true;
                }
                
                auto [val, left, right] = *node;
                if (val != value) {
                    return false;
                }
                
                return treeDfs(left, treeDfs) && treeDfs(right, treeDfs);
        };
        

        return dfs(root, dfs);
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        stack<TreeNode*> st;
        const int value = root->val;

        while (st.empty() == false || root != nullptr) {
            while (root != nullptr) {
                if (root->val !=  value) {
                    return false;
                }
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
        return true;
    }
};