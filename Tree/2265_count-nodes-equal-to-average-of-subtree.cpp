/** Original Solution 1
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
    int averageOfSubtree(TreeNode* root) {
        auto equalNodeCnt = 0;
        auto dfs = [&](TreeNode* parent, auto&& self) ->pair<int, int> {
            if (parent == nullptr) {
                return {0, 0};
            }

            auto leftPair = self(parent->left, self);
            auto rightPair = self(parent->right, self);

            int sum = leftPair.first + rightPair.first + parent->val;
            int nodeCnt = leftPair.second + rightPair.second + 1;
            int average = sum / nodeCnt;

            equalNodeCnt += static_cast<int>(parent->val == average);

            return {sum, nodeCnt};
        };

        dfs(root, dfs);

        return equalNodeCnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](auto&& dfs, TreeNode* node) -> pair<int, int> {
            if (!node) {
                return {0, 0};
            }
            auto [leftSum, leftSize] = dfs(dfs, node->left);
            auto [rightSum, rightSize] = dfs(dfs, node->right);
            int Size = leftSize + rightSize + 1;
            int Sum = leftSum + rightSum + node->val;
            if (Size && Sum / Size == node->val) {
                ans++;
            }
            return {Sum, Size};
        };
        dfs(dfs, root);
        return ans;
    }
};
