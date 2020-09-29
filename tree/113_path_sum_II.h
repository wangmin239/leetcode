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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> vec;
        if (root != nullptr) {
            getPath(root, sum, vec, res);
        }
        return res;
    }

    void getPath(TreeNode* root, int sum, vector<int>& vec, vector<vector<int>>& res) {
        auto [val, left, right] = *root;
        
        sum -= val;
        vec.emplace_back(val);
        if (sum == 0 && left == nullptr && right == nullptr) {
            res.emplace_back(vec);
        }
        if (left != nullptr) {
            getPath(left, sum, vec, res);
        }
        if (right != nullptr) {
            getPath(right, sum, vec, res);
        }
        vec.pop_back();
    }
};