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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *prev;
        auto node = root;
        while (node != nullptr || !st.empty()) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                while(node->right == nullptr && !st.empty()) {         
                    auto ancestor = st.top();
                    st.pop();
                    swap(node->right, ancestor->right);
                }
                swap(node->right, node->left);
                node = node->left;
            }
        }

        flipTree(root);         
    }

    void flipTree(TreeNode* root) {
        while (root != nullptr) {
            swap(root->left, root->right);
            root = root->right;
        }
    }
};
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};


class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        auto stk = stack<TreeNode*>();
        stk.push(root);
        TreeNode *prev = nullptr;
        while (!stk.empty()) {
            TreeNode *curr = stk.top(); stk.pop();
            if (prev != nullptr) {
                prev->left = nullptr;
                prev->right = curr;
            }
            TreeNode *left = curr->left, *right = curr->right;
            if (right != nullptr) {
                stk.push(right);
            }
            if (left != nullptr) {
                stk.push(left);
            }
            prev = curr;
        }
    }
};