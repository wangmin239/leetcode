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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr) {
            return nullptr;
        }
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        if (depth == 2) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        } else {
            root->left = addOneRow(root->left, val, depth - 1);
            root->right = addOneRow(root->right, val, depth - 1);
        }
        return root;
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val, root, nullptr);
            return node;
        }
        
        
        dfs(root, 1, depth, val);
        return root;
    }
    
    
    void dfs(TreeNode* root, int curDepth, const int depth, const int data) {
        if (root == nullptr) {
            return;
        }
        
        if (curDepth + 1 == depth) {
            root->left = new TreeNode(data, root->left, nullptr);
            root->right = new TreeNode(data, nullptr, root->right);
            return;
        }

        dfs(root->left, curDepth + 1, depth, data);
        dfs(root->right, curDepth + 1, depth, data);
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        vector<TreeNode *> curLevel(1, root);
        for (int i = 1; i < depth - 1; i++) {
            vector<TreeNode *> tmpt;
            for (auto &node : curLevel) {
                if (node->left != nullptr) {
                    tmpt.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    tmpt.emplace_back(node->right);
                }
            }
            curLevel = move(tmpt);
        }
        for (auto &node : curLevel) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        return root;
    }
};
