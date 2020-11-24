class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        /* obtain the height of the tree */
        int height = 0;
        auto node = root;
        while (node->left != nullptr) {
            node = node->left;
            height++;
        }

        int low = 1 << height;
        int high = (1 << (height + 1)) - 1;
        while (low < high){
            int mid = (high - low + 1) / 2 + low;
            if (isExists(root, height, mid) == true) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool isExists(TreeNode *root, int height, int nodeIndex) {
        int bits = 1 << (height - 1);
        while (root != nullptr && bits > 0) {
            if (bits & nodeIndex) {
                root = root->right;
            } else {
                root = root->left;
            }
            bits >>= 1;
        }
        return root != nullptr;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        stack<TreeNode*> st;
        
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root =  st.top();
                auto [val, left, right] = *root;
                if (right == nullptr) {
                    count++;
                    st.pop();
                } else {
                    root->right = nullptr;
                }
                root = right;
            }
        }
        return count;
    }
};