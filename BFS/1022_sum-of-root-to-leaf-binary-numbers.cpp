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
        auto dfs = [&sum](TreeNode* node, int curSum, auto&& self) {
            curSum <<= 1;
            curSum += node->val;

            if (node->left == nullptr && node->right == nullptr) {
                sum += curSum;
                return;
            }

            if (node->left != nullptr) {
                self(node->left, curSum , self);
            }
            if (node->right != nullptr) {
                self(node->right, curSum, self);
            }
        };

        dfs(root, 0, dfs);
        return sum;
    }
};


/* Official Solution 1 */
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
