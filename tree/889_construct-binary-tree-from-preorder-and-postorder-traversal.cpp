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
    //前序遍历和后序遍历访问顺序本质区别
    //前序:走一步，记录一步.  后序: 每次走到头，回一步，记录一步。
    //所以直接利用前序建树，利用后序返回，相当于前序递归访问，利用后序遍历返回上一节点
    //将后序遍历充当前序遍历中的返回栈
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> stack;
        stack.push_back(new TreeNode(pre[0]));
        for(int i = 1, j = 0; i < pre.size(); ++i){
            TreeNode* node = new TreeNode(pre[i]);
            
            while(stack.back()->val == post[j]) {
                stack.pop_back();
                j++;
            }
            
            if (stack.back()->left == nullptr) {
                stack.back()->left = node;
            } else {
                stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack.front();
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
    int preindex = 0,posindex = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preindex++]);
        if(post[posindex] != root->val)
            root->left = constructFromPrePost(pre,post);
        if(post[posindex] != root->val)
            root->right = constructFromPrePost(pre,post);
        posindex++;
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildDfs(0, 0, preorder.size(), preorder, postorder);
    }
    
    TreeNode* buildDfs(int preIndex, int postIndex, int len, vector<int>& pre, vector<int>& post) {
        if (len == 0) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(pre[preIndex]);
        if (len == 1) {
            return root;
        }
        int sentinel = 1;
        while (sentinel < len) {
            if (post[postIndex + sentinel - 1] == pre[preIndex + 1]) {
                break;
            }
            ++sentinel;
        }
        
        root->left = buildDfs(preIndex + 1, postIndex, sentinel, pre, post);
        root->right = buildDfs(preIndex + sentinel + 1, postIndex + sentinel, len - 1 - sentinel, pre, post);
        return root;
    }
};