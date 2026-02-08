
/**
 * Original Solution 1
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
    bool isBalanced(TreeNode* root) {
        bool isAllBalanced = true;
        auto dfs = [&isAllBalanced](TreeNode* node, auto&& self) {
            if (node == nullptr) {
                return 0;
            }

            int leftHeight = self(node->left, self);
            int rightHeight = self(node->right, self);

            if (abs(leftHeight - rightHeight) > 1) {
                isAllBalanced = false;
            }
            return max(leftHeight, rightHeight) + 1;
        };

        dfs(root, dfs);
        return isAllBalanced;
    }
};

/* Official Solution 1 */
class Solution {
    int get_height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_h = get_height(node->left);
        if (left_h == -1) {
            return -1; // 提前退出，不再递归
        }
        int right_h = get_height(node->right);
        if (right_h == -1 || abs(left_h - right_h) > 1) {
            return -1;
        }
        return max(left_h, right_h) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
};
