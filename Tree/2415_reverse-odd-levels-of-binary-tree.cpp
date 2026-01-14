class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> qu;
        qu.emplace(root);
        bool isOdd = false;
        while (!qu.empty()) {
            int sz = qu.size();
            vector<TreeNode *> arr;
            for (int i = 0; i < sz; i++) {
                TreeNode *node = qu.front();
                qu.pop();
                if (isOdd) {
                    arr.emplace_back(node);
                }
                if (node->left) {
                    qu.emplace(node->left);
                    qu.emplace(node->right);
                }
            }
            if (isOdd) {
                for (int l = 0, r = sz - 1; l < r; l++, r--) {
                    swap(arr[l]->val, arr[r]->val);
                }
            }            
            isOdd ^= true;
        }
        return root;
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }

    void dfs(TreeNode *root1, TreeNode *root2, bool isOdd) {
        if (root1 == nullptr) {
            return;
        }
        if (isOdd) {
            swap(root1->val, root2->val);
        }
        dfs(root1->left, root2->right, !isOdd);
        dfs(root1->right, root2->left, !isOdd);
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>  que;
        stack<int> vals;
        int layer = 0;
        
        que.push(root);
        while (que.empty() != true) {
            int size = que.size();
            while (size--) {
                auto node = que.front();
                auto [val, left, right] = *node;
                que.pop();

                if (left != nullptr) {
                  que.push(left);
                  que.push(right);
                  if ((layer & 0x1) == 0x0) {
                    vals.push(left->val);
                    vals.push(right->val);                      
                  }
                }
                
                if (layer & 0x1) {
                    node->val = vals.top();
                    vals.pop();
                }
            }
            ++layer;
        }
        return root;
    }
};