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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        
        if (root == nullptr) {
            return root;
        }
        
        if (key == root->val) {
            if (root->right == nullptr) {
                return root->left;
            }
            
            getLeaf(root->right)->left = root->left;
            return root->right;
        }
        parent = root;
        if (key < root->val) {
            return findNode(parent->left, parent, key);
        }
        
        return findNode(parent->right, parent, key);
            
    }
    
    TreeNode* findNode(TreeNode* node, TreeNode* parent, int key) {
        if (node == nullptr) {
            return parent;
        }
        
        auto [val, left, right] = *node;

        if (val < key) {
            if (node == parent->left) {
                parent->left = findNode(right, node, key);
            } else {
                parent->right = findNode(right, node, key);
            }
        } else if (val > key) {
            if (node == parent->left) {
                parent->left = findNode(left, node, key);
            } else {
                parent->right = findNode(left, node, key);
            }
        } else {
            concatNode(node, parent);
        }
        
        return parent;
    }
    
    
    TreeNode* getLeaf(TreeNode* node) {
        auto [val, left, right] = *node;
        
        if (left == nullptr) {
            return node;
        }
        
        return getLeaf(left);
    }
    
    
    void concatNode(TreeNode* node, TreeNode* parent) {
        if (node == parent->left) {
            if (node->right == nullptr) {
                parent->left = node->left;
            } else {
                parent->left = node->right;
                getLeaf(node->right)->left = node->left;
            }
        } else {
            if (node->right == nullptr) {
                parent->right = node->left;
            } else {
                parent->right = node->right;
                getLeaf(node->right)->left = node->left;
            }
        }
        
    }
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == nullptr) {
            return nullptr;
        }
        
        auto [val, left, right] = *root;
        
        if (val < key) {
            root->right = deleteNode(right, key);
        }
        
        if (val > key) {
            root->left = deleteNode(left, key);
        }
        
        if (val == key) {
            if (right == nullptr) {
                return left;
            }
            
            if (left == nullptr) {
                return right;
            }
            
            auto node = right;   
            
            while (node->left != nullptr) {
                node = node->left;
            }
            node->left = left;
            root = right;
        }
        return root;
    }
};




class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == nullptr)    return nullptr;
        if (key > root->val)    root->right = deleteNode(root->right, key);     
        else if (key < root->val)    root->left = deleteNode(root->left, key);  
        else    
        {
            if (! root->left)   return root->right; 
            if (! root->right)  return root->left;  
            TreeNode* node = root->right;            
            while (node->left)          
                node = node->left;
            node->left = root->left;    
            root = root->right;         
        }
        return root;    
    }
};



class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (!root->right) {
                return root->left;
            }
            if (!root->left) {
                return root->right;
            }
            TreeNode *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val);
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *curParent = nullptr;
        while (cur && cur->val != key) {
            curParent = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (!cur) {
            return root;
        }
        if (!cur->left && !cur->right) {
            cur = nullptr;
        } else if (!cur->right) {
            cur = cur->left;
        } else if (!cur->left) {
            cur = cur->right;
        } else {
            TreeNode *successor = cur->right, *successorParent = cur;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }
            if (successorParent->val == cur->val) {
                successorParent->right = successor->right;
            } else {
                successorParent->left = successor->right;
            }
            successor->right = cur->right;
            successor->left = cur->left;
            cur = successor;
        }
        if (!curParent) {
            return cur;
        } else {
            if (curParent->left && curParent->left->val == key) {
                curParent->left = cur;
            } else {
                curParent->right = cur;
            }
            return root;
        }
    }
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == nullptr)    return nullptr;
        if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
        else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
        else    // 当前节点就是要删除的节点
        {
            if (! root->left)   return root->right; // 情况1，欲删除节点无左子
            if (! root->right)  return root->left;  // 情况2，欲删除节点无右子
            TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有 
            TreeNode* pre=root;
            while (node->left)          // 寻找欲删除节点右子树的最左节点
            {
                pre=node;
                node = node->left;
            }
            root->val=node->val; // 欲删除节点的下一个值顶替其位置，节点被删除
           if(pre->left->val==node->val) pre->left = node->right;    // 将下一个值的节点删除   
           else pre->right=node->right;    
        }
        return root;    
    }
};