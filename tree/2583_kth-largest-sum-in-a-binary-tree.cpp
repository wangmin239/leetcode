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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> q;
        q.push(root);
        vector<long long> levelSumArray;
        while (!q.empty()) {
            long long levelSum = 0, size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            levelSumArray.push_back(levelSum);
        }
        if (levelSumArray.size() < k) {
            return -1;
        }
        sort(levelSumArray.begin(), levelSumArray.end());
        return *(levelSumArray.end() - k);
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> que;
        vector<long long> ans;
        st.push(root);
        
        
        while (que.empty() == false) {
            int size = que.size();
            long long sum = 0;
            while (size-- > 0) {
                auto node = que.front();
                que.pop();
                sum += node->val;
                
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                
                if (node->right != nullptr) {
                    que.push(node->right);
                }                
            }
            ans.push_back(sum);
        }
        
        if (ans.size() < k) {
            return -1;
        }
        
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k - 1];
    }
};