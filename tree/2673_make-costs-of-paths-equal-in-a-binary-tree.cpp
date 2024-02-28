class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n - 2; i > 0; i -= 2) {
            ans += abs(cost[i] - cost[i + 1]);
            // 叶节点 i 和 i+1 的双亲节点下标为 i/2（整数除法）
            cost[i / 2] += max(cost[i], cost[i + 1]);
        }
        return ans;
    }
};

/* Definition of one node in a binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};






class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        TreeNode *root = new TreeNode(cost.front());
        queue<TreeNode*> que;
        
        que.push(root);
        
        /* construct a binary tree */
        for (int i = 1; i < n; ) {
            int size = que.size();
            while (size-- != 0) {
                auto node = que.front();
                que.pop();
                node->left = new TreeNode(cost[i++]);
                node->right = new TreeNode(cost[i++]);
                que.push(node->left);
                que.push(node->right);
            }
        } 
        
        int steps = 0;
        dfs(root, steps);
        
        /* Destruct a binary tree */
        function<void(TreeNode*)> destroyDFS = [](TreeNode* node) {
            if (node == nullptr) {
                return ;
            }
            destroyDFS(node->left);
            destroyDFS(node->right);
            delete node;
            node = nullptr;
        };
        destroyDFS(root);
        
        return steps;
    }
    
    
    int dfs(TreeNode *parent, int& steps) {
        if (parent->left == nullptr) {
            return parent->val;
        }
        
        int leftSum = dfs(parent->left, steps);
        int rightSum = dfs(parent->right, steps);
        steps += abs(leftSum - rightSum);
        return parent->val + max(leftSum, rightSum);
    }
};
 
 