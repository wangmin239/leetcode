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
    int dfs(TreeNode *root, int mi, int ma) {
        if (root == nullptr) {
            return 0;
        }
        int diff = max(abs(root->val - mi), abs(root->val - ma));
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        diff = max(diff, dfs(root->left, mi, ma));
        diff = max(diff, dfs(root->right, mi, ma));
        return diff;
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
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
    int maxAncestorDiff(TreeNode* root) {
        int maxVal = 0;
        stack<TreeNode*> st;
        for (TreeNode* node = root; !st.empty() || node != nullptr; ) {
            if (node != nullptr) {
                st.push(node);
                maxVal = max(maxVal, getMaxDiff(node));
                node = node->left;
                continue;
            }
            node = st.top();
            node = node->right;
            st.pop();
        }
        return maxVal;
    }
    
    
    int getMaxDiff(TreeNode* root) {
        int maxVal = 0;
        stack<TreeNode*> st;
        for (TreeNode* node = root; !st.empty() || node != nullptr; ) {
            if (node != nullptr) {
                st.push(node);
                maxVal = max(maxVal, abs(root->val - node->val));
                node = node->left;
                continue;
            }
            node = st.top();
            node = node->right;
            st.pop();
        }
        
        return maxVal;
    }
};