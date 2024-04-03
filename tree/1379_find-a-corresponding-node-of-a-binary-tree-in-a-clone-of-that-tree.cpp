
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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        queue<TreeNode *> q1, q2;
        q1.push(original);
        q2.push(cloned);
        while (!q1.empty()) {
            TreeNode *node1 = q1.front(), *node2 = q2.front();
            q1.pop();
            q2.pop();
            if (node1 == target) {
                return node2;
            }
            if (node1->left != nullptr) {
                q1.push(node1->left);
                q2.push(node2->left);
            }
            if (node1->right != nullptr) {
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }
        return nullptr; // impossible case
    }
};


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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original == nullptr) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        if (left != nullptr) {
            return left;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};



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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> originQue;    
        originQue.push(original);
        
        queue<TreeNode*> cloneQue;
        cloneQue.push(cloned);
        
        while (originQue.empty() == false) {
            int size = originQue.size();
            
            while (size--) {
                auto originNode = originQue.front();
                auto cloneNode = cloneQue.front();
                
                if (originNode == target) {
                    return cloneNode;
                }
                originQue.pop();
                cloneQue.pop();
                
                if (originNode->left) {
                    originQue.push(originNode->left);
                    cloneQue.push(cloneNode->left);
                }
                
                if (originNode->right) {
                    originQue.push(originNode->right);
                    cloneQue.push(cloneNode->right);
                }
                
            }  
        }
        
        return nullptr;
    }
};





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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        }
        
        if (target == original) {
            return cloned;
        }
        
        auto cloneNode = getTargetCopy(original->left, cloned->left, target);
        if (cloneNode != nullptr) {
            return cloneNode;
        }
        
        return getTargetCopy(original->right, cloned->right, target);
    }
};




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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> originSt;
        stack<TreeNode*> cloneSt;
        
        while (originSt.empty() == false || original != nullptr) {
            if (target == original) {
                return cloned;
            }
            if (original != nullptr) {
                originSt.push(original);
                original = original->left;
                cloneSt.push(cloned);
                cloned = cloned->left;
            } else {
                auto originNode = originSt.top();
                originSt.pop();
                original = originNode->right;
                
                auto cloneNode = cloneSt.top();
                cloneSt.pop();
                cloned = cloneNode->right;
            }
            
            
        }
        
        return nullptr;
    }
};