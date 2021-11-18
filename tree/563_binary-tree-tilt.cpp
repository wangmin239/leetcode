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
    int findTilt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        auto [val, left, right] = *root;
        auto sum = [](const TreeNode* parent, auto&& dfs) {
            if (parent == nullptr) {
                return 0;
            }
            auto [val, left, right] = *parent;
            return val + dfs(left, dfs) + dfs(right, dfs);
        };
        int tilt = abs(sum(left, sum) - sum(right, sum));
        return tilt + findTilt(left) + findTilt(right);
        
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
    int ans = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sumLeft = dfs(node->left);
        int sumRight = dfs(node->right);
        ans += abs(sumLeft - sumRight);
        return sumLeft + sumRight + node->val;
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
    int findTilt(TreeNode* root) {
        int sum = 0;
        int tilt = 0;
        dfs(root, sum, tilt);
        return tilt;
    }
    
    void dfs(TreeNode* parent, int& sum, int& tilt) {
        if (parent == nullptr) {
            return ;
        }
        
        auto [val, left, right] = *parent;
        int sumLeft = 0;
        int sumRight = 0;
        int tiltLeft = 0;
        int tiltRight = 0;
        dfs(left, sumLeft, tiltLeft);
        dfs(right, sumRight, tiltRight);
        sum = sumLeft + sumRight + val;
        parent->val = abs(sumLeft - sumRight);
        tilt = tiltLeft + tiltRight + parent->val;
        return;
    }
    

};