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
    int maxLevelSum(TreeNode* root) {
       int maxSum = root->val;
       int maxLayer = 1;
       queue<TreeNode*> que;
       int depth = 1;
       que.push(root);
       
       while (que.empty() == false) {
           int size = que.size();
           int curSum = 0;
           while (size-- != 0) {
               auto node = que.front();
               auto [val, left, right] = *node;
               
               que.pop();
               curSum += val;
               if (left != nullptr) {
                   que.push(left);
               }
               
               if (right != nullptr) {
                   que.push(right);
               }
           }
           
           if (curSum > maxSum) {
               maxSum = curSum;
               maxLayer = depth;
           }
           depth++;
       }
       
       return maxLayer;
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
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        
        dfs(root, 0, sum);
        
        auto iter = max_element(sum.begin(), sum.end());
        
        return iter - sum.begin() + 1;

    }
    
    void dfs(TreeNode* node, int depth, vector<int>& sum) {
        auto [val, left, right] = *node;
        
        if (sum.size() == depth) {
            sum.push_back(val);
        } else {
            sum[depth] += val;
        }
        
        if (left != nullptr) {
            dfs(left, depth + 1, sum);
        }
        
        if (right != nullptr) {
            dfs(right, depth + 1, sum);
        }
        
    }
};