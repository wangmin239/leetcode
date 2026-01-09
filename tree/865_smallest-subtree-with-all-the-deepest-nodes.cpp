/**
 * Original Solution 2
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> nodeHeight;
        auto getHeight = [&](TreeNode* node, auto&& self) {
            if (node == nullptr) {
                return 0;
            }

            int height = max(self(node->left, self), self(node->right, self)) + 1;
            nodeHeight[node] = height;
            return height;
        };

        auto getSubtreeRoot = [&](TreeNode* node, auto&& self) {
            auto left = node->left;
            auto right = node->right;
            int leftDepth = 0;
            int rightDepth = 0;

            if (left != nullptr) {
                leftDepth = nodeHeight[left];
            }

            if (right != nullptr) {
                rightDepth = nodeHeight[right];
            }

            if (leftDepth == rightDepth) {
                return node;
            }

            if (leftDepth < rightDepth) {
                return self(right, self);
            }

            return self(left, self);
        };

        getHeight(root, getHeight);

        return getSubtreeRoot(root, getSubtreeRoot);
    }
};


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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* subtreeRoot = root;
        auto dfs = [&](TreeNode* node, auto&& self) {
            if (node == nullptr) {
                return 0;
            }

            int leftDepth = self(node->left, self) + 1;
            int rightDepth = self(node->right, self) + 1;

            if (leftDepth == rightDepth) {
                subtreeRoot = node;
                return leftDepth;
            }

            if (leftDepth < rightDepth) {
                self(node->right, self);
            }

            if (leftDepth > rightDepth) {
                self(node->left, self);
            }

            return max(leftDepth, rightDepth);
        };

        dfs(root, dfs);
        return subtreeRoot;
    }
};



/**
 * Official Solution 1
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

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return f(root).first;
    }
};



/**
 * Official Solution 2
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int max_depth = -1; // 全局最大深度
        TreeNode* ans;

        auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) {
            if (node == nullptr) {
                max_depth = max(max_depth, depth); // 维护全局最大深度
                return depth;
            }

            int left_max_depth = dfs(node->left, depth + 1); // 获取左子树最深叶节点的深度
            int right_max_depth = dfs(node->right, depth + 1); // 获取右子树最深叶节点的深度

            if (left_max_depth == right_max_depth && left_max_depth == max_depth) {
                ans = node; // node 可能是答案
            }

            return max(left_max_depth, right_max_depth); // 当前子树最深叶节点的深度
        };

        dfs(root, 0);
        return ans;
    }
};
