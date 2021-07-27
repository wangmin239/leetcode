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
    int findSecondMinimumValue(TreeNode* root) {     
        stack<TreeNode*> nodeSt;
        vector<int> ansVec;
        
        while (root != nullptr || nodeSt.empty() != true) {
            if (root != nullptr) {
                auto [val, left, right] = *root;
                ansVec.push_back(val);
                nodeSt.push(root);
                root = left;
            } else {
                root = nodeSt.top();
                nodeSt.pop();
                root = root->right;
            }
        }
        
        sort(ansVec.begin(), ansVec.end());
        
        int secondMinVal = ansVec.front();
        for (auto val : ansVec) {
            if (val > secondMinVal) {
                return val;
            }
        }
        return -1;
    }
};





class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        int rootvalue = root->val;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            if (ans != -1 && node->val >= ans) {
                return;
            }
            if (node->val > rootvalue) {
                ans = node->val;
            }
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};
