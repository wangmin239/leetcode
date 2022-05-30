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
    int sumRootToLeaf(TreeNode* root) {
        auto [val, left, right] = *root;
        int sum = 0;
        
        if (left == nullptr && right == nullptr) {
            return val;
        }
        
        if (left != nullptr) {
            left->val += val << 1;
            sum += sumRootToLeaf(left);
        }
        
        if (right != nullptr) {
            right->val += val << 1;
            sum += sumRootToLeaf(right);
        }
        return  sum;
    }
   
};


class Solution {
public:
    int dfs(TreeNode *root, int val) {
        if (root == nullptr) {
            return 0;
        }
        val = (val << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        }
        return dfs(root->left, val) + dfs(root->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> que;
        que.push(root);
        
        while (que.empty() != true) {
            int size = que.size();
            while (size-- != 0) {
                auto node = que.front();
                que.pop();
                
                auto [val, left, right] = *node;
                
                if (left != nullptr) {
                    left->val += val << 1;
                    que.push(left);
                } 
                
                if (right != nullptr) {
                    right->val += val << 1;
                    que.push(right);
                }
                
                if (left == nullptr && right == nullptr) {
                    sum += val;
                }
                
            }
            
        }
        return sum;
    }
   
};


class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        stack<TreeNode *> st;
        int val = 0, ret = 0;
        TreeNode *prev = nullptr;
        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                val = (val << 1) | root->val;
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if (root->right == nullptr || root->right == prev) {
                if (root->left == nullptr && root->right == nullptr) {
                    ret += val;
                }
                val >>= 1;
                st.pop();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};
