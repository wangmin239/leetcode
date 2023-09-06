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
    pair<TreeNode*, int> f(TreeNode* root) {
        if (!root) {
            return {root, 0};
        }

        auto left = f(root->left);
        auto right = f(root->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {root, left.second + 1};

    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return f(root).first;
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        
        int lDeepth = getDeepth(root->left);
        int rDeepth = getDeepth(root->right);
        
        if (lDeepth == rDeepth) {
            return root;
        }
        
        if (lDeepth < rDeepth) {
            return lcaDeepestLeaves(root->right);
        }
        return lcaDeepestLeaves(root->left);
    }
    
    int getDeepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return 1 + max(getDeepth(root->left), getDeepth(root->right));
    }

};