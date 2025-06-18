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
    int findTargetNode(TreeNode* root, int cnt) {
        int ans = 0;
        auto dfs = [&ans](TreeNode* node, int& index, auto&& innerDfs)->void {
            auto [val, left, right] = *node;
            if (right != nullptr) {
                innerDfs(right, index, innerDfs);
            }

            if (--index == 0) {
                ans = val;
                return ;
            }
            if (left != nullptr) {
                innerDfs(left, index, innerDfs);
            }
            
        };
        
        dfs(root, cnt, dfs);
        return ans;
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
    int findTargetNode(TreeNode* root, int cnt) {
        stack<TreeNode*> st;
        int ans = 0;
        
        while (st.empty() == false || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                root = root->right;
                continue;
            }
            root = st.top();
            if (--cnt == 0) {
                ans = root->val;
                break;
            }
            st.pop();
            root = root->left;
        }
        return ans;
    }
};
