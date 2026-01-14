/**
 * Original Solution 1
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
    int maxProduct(TreeNode* root) {
        auto getSum = [&](TreeNode* node, auto&& self) ->unsigned int {
            if (node == nullptr) {
                return 0LL;
            }
            auto [val, left, right] = *node;
            return val + self(left, self) + self(right, self);
        };

        auto sum = getSum(root, getSum);
        const int mod = 1e9 + 7;
        long long maxMultply = 0;


        auto getMultiply = [&](TreeNode* parent, auto&& self) -> unsigned int {
            auto [val, left, right] = *parent;
            auto leftSum = 0;
            auto rightSum = 0;

            if (left != nullptr) {
                leftSum = self(left, self);
                maxMultply = max(maxMultply, 1LL * leftSum * (sum - leftSum));

            }

            if (right != nullptr) {
                rightSum = self(right, self);
                maxMultply = max(maxMultply, 1LL * rightSum * (sum - rightSum));
            }

            return leftSum + rightSum + val;
        };

        getMultiply(root, getMultiply);
        return maxMultply % mod;
    }
};


/* Official Solution 1 */
class Solution {
private:
    int sum = 0;
    int best = 0;

public:
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        sum += node->val;
        dfs(node->left);
        dfs(node->right);
    }

    int dfs2(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int cur = dfs2(node->left) + dfs2(node->right) + node->val;
        if (abs(cur*2 - sum) < abs(best*2 - sum)) {
            best = cur;
        }
        return cur;
    }

    int maxProduct(TreeNode* root) {
        dfs(root);
        dfs2(root);
        return (long long)best * (sum - best) % 1000000007;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        auto dfs1 = [&](this auto&& dfs1, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            return node->val + dfs1(node->left) + dfs1(node->right);
        };
        long long total = dfs1(root);

        long long ans = 0;
        auto dfs2 = [&](this auto&& dfs2, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int s = node->val + dfs2(node->left) + dfs2(node->right);
            ans = max(ans, s * (total - s));
            return s;
        };
        dfs2(root);

        return ans % 1'000'000'007;
    }
};
