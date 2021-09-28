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
    int pathSum(TreeNode* root, int targetSum) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int remain) {
            if (node == nullptr) {
                return 0;
            }
            auto [val, left, right] = *node;
            auto sum = 0;
            if (val == remain) {
                sum = 1;
            }
            
            return sum + dfs(left, remain - val) + dfs(right, remain - val);
        };
        
        int sum = 0;
        queue<TreeNode*> que;
        
        if (root != nullptr) {
            que.push(root);
        }
        
        while (que.empty() != true) {
            for (int size = que.size(); size > 0; size--){
                auto node = que.front();
                que.pop();

                auto [val, left, right] = *node;
                if (left != nullptr) {
                    que.push(left);
                }
                
                if (right != nullptr) {
                    que.push(right);
                }
                sum += dfs(node, targetSum);
            }
        }
        
        return sum;      
    }
};


class Solution {
public:
    unordered_map<int, int> prefix;

    int dfs(TreeNode *root, long long curr, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr - targetSum];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};


class Solution {
public:
    int rootSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        if (root->val == targetSum) {
            ret++;
        } 

        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        
        int ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
};
