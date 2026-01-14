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
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        int lsz, rsz;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) {
            if (node == nullptr)
                return 0;
            int ls = dfs(node->left);
            int rs = dfs(node->right);
            if (node->val == x)
                lsz = ls, rsz = rs;
            return ls + rs + 1;
        };
        dfs(root);
        return max({lsz, rsz, n - 1 - lsz - rsz}) * 2 > n;
    }
};


class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int total = 0, target_left = 0, target_right = 0;
        auto dfs = [&](TreeNode* node, auto&& dfs)->int {
            if (!node) return 0;
            int ret = 1;
            int left = dfs(node->left, dfs);
            int right = dfs(node->right, dfs);
            if (node->val == x) target_left = left, target_right = right;
            return ret + left + right;
        };
        total = dfs(root, dfs);
        return total > 2 * (target_left + target_right + 1) || 2 * max(target_left, target_right) > total;
    }
}; 

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xNode = find(root, x);
        int leftSize = getSubtreeSize(xNode->left);
        if (leftSize >= (n + 1) / 2) {
            return true;
        }
        int rightSize = getSubtreeSize(xNode->right);
        if (rightSize >= (n + 1) / 2) {
            return true;
        }
        int remain = n - 1 - leftSize - rightSize;
        return remain >= (n + 1) / 2;
    }

    TreeNode* find(TreeNode *node, int x) {
        if (node == NULL) {
            return NULL;
        }
        if (node->val == x) {
            return node;
        }
        TreeNode* res = find(node->left, x);
        if (res != NULL) {
            return res;
        } else {
            return find(node->right, x);
        }
    }

    int getSubtreeSize(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
};
