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
    int distributeCoins(TreeNode* root) {
        int move = 0;

        function<int(const TreeNode *)> dfs = [&](const TreeNode *root) -> int {
            int moveleft = 0;
            int moveright = 0;
            if (root == nullptr) {
                return 0;
            }
            if (root->left) {
                moveleft = dfs(root->left);
            }        
            if (root->right) {
                moveright = dfs(root->right);
            }
            move += abs(moveleft) + abs(moveright);
            return moveleft + moveright + root->val - 1;
        };

        dfs(root);
        return move;
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
    int distributeCoins(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        auto [_, left, right] = *root;
        int steps = distributeCoins(left);

        steps += distributeCoins(right);

        if (left != nullptr) {
            steps += abs(left->val - 1);
            root->val += left->val - 1;
        }
        if (right != nullptr) {
            steps += abs(right->val - 1);
            root->val += right->val - 1;
        }
        return steps;
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
    int distributeCoins(TreeNode* root) {
        int steps = 0;
        dfs(root, steps);
        return steps;
    }

    void dfs(TreeNode* node, int& moves) {
        if (node == nullptr) {
            return ;
        }

        auto [val, left, right] = *node;
        dfs(left, moves);
        dfs(right, moves);
        if (left != nullptr) {
            if (left->val != 1) {
                moves += abs(left->val - 1);
            } 
            node->val += left->val - 1;
        }

        if (right != nullptr) {
            if (right->val != 1) {
                moves += abs(right->val - 1);
            } 
            node->val += right->val - 1;
        }
    }
};