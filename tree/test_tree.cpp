class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        int minVal = INT_MAX;
        int pre = -1;
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                auto root = st.top();
                st.pop();
                if (pre != -1) {
                    minVal = min(minVal, root->val - pre);
                }
                pre = root->val;
                root = root->right;
            }            
        }

        return minVal;
    }
};