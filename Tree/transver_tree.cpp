class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                auto [val, left, right] = *root;
                /* the parent node has right child, marking the right child is visited. */
                if (right != nullptr) {
                    root->right = nullptr;
                    root = right;
                } else {
                    res.emplace_back(val);
                    st.pop();
                    root = nullptr;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                result.emplace_back(root->val);
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return result;

    }
};