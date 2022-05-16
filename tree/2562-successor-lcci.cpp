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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        vector<TreeNode*> vec;

        
        while (root != nullptr || st.empty() != true) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                vec.push_back(root);
                root = root->right;
            }     
        }
        
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == p) {
                break;
            }
        }
        
        return i < vec.size() - 1 ? vec[i + 1] : nullptr;
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode *prev = nullptr, *curr = root;
        while (!st.empty() || curr != nullptr) {
            while (curr != nullptr) {
                st.emplace(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (prev == p) {
                return curr;
            }
            prev = curr;
            curr = curr->right;
        }
        return nullptr;
    }
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) {
            return nullptr;
        }
        
        if(p->val < root->val) {
            return (p = inorderSuccessor(root->left, p)) ? p : root;
        }
        
        return inorderSuccessor(root->right, p);
    }
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return root ? p->val < root->val ? (p = inorderSuccessor(root->left, p)) ? p : root : inorderSuccessor(root->right, p) : nullptr;
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      　stack<TreeNode*> st;
      　TreeNode* cur = root;
      　TreeNode* next = nullptr;
      
       while (cur != nullptr) {
           if (cur->val > p->val) {
               next = cur;
               cur = cur->left;
           } else {
               cur = cur->right;
           }
       }
       return next;
    }
};