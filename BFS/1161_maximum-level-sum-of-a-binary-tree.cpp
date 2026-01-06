/** 
 * Original Solution 2, DFS
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
    int maxLevelSum(TreeNode* root) {
        vector<long long> levelSum;
        auto dfs = [&](TreeNode* node, int depth, auto&& self) {
            if (node == nullptr) {
                return ;
            }
            if (levelSum.size() < depth + 1) {
                levelSum.push_back(0LL);
            }
            levelSum[depth] += node->val;
            self(node->left, depth + 1, self);
            self(node->right, depth + 1, self);
            
        };

        dfs(root, 0, dfs);
        auto maxIter = max_element(levelSum.begin(), levelSum.end());
        
        return maxIter - levelSum.begin() + 1;
    }
};
/** 
 * Original Solution 1, BFS
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
    int maxLevelSum(TreeNode* root) {
        int curLevel = 0;
        long long  maxSum = LONG_MIN;
        int maxLevel = 0;
        queue<TreeNode*> que;

        que.push(root);

        while (que.empty() != true) {
            int size = que.size();
            long long levelSum = 0;

            ++curLevel;
            while (size--) {
                auto node = que.front();
                que.pop();

                levelSum += node->val;
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }

            if (maxSum < levelSum) {
                maxSum = levelSum;
                maxLevel = curLevel;
            }
        }

        return maxLevel;
    }
};


/* Official Solution 1 */
class Solution {
    vector<int> sum;

    void dfs(TreeNode *node, int level) {
        if (level == sum.size()) {
            sum.push_back(node->val);
        } else {
            sum[level] += node->val;
        }
        if (node->left) {
            dfs(node->left, level + 1);
        }
        if (node->right) {
            dfs(node->right, level + 1);
        }
    }

public:
    int maxLevelSum(TreeNode *root) {
        dfs(root, 0);
        int ans = 0;
        for (int i = 0; i < sum.size(); ++i) {
            if (sum[i] > sum[ans]) {
                ans = i;
            }
        }
        return ans + 1; // 层号从 1 开始
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxLevelSum(TreeNode *root) {
        int ans = 1, maxSum = root->val;
        vector<TreeNode*> q = {root};
        for (int level = 1; !q.empty(); ++level) {
            vector<TreeNode*> nq;
            int sum = 0;
            for (auto node : q) {
                sum += node->val;
                if (node->left) {
                    nq.emplace_back(node->left);
                }
                if (node->right) {
                    nq.emplace_back(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
            q = move(nq);
        }
        return ans;
    }
};
