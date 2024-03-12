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
class FindElements {
public:
    unordered_set<int> numSet;
    FindElements(TreeNode* root) {
        queue<TreeNode*> nodeQ;
        
        if (root != nullptr) {
            root->val = 0;
            nodeQ.push(root);
            numSet.insert(root->val);
        }
        
        while (nodeQ.empty() == false) {
            int size = nodeQ.size();
            while (size-- != 0) {
                auto node = nodeQ.front();
                nodeQ.pop();
                
                if (node->left != nullptr) {
                    node->left->val = (node->val << 1) + 1;
                    nodeQ.push(node->left);
                    numSet.insert(node->left->val);
                }
                
                if (node->right != nullptr) {
                    node->right->val = (node->val << 1) + 2;
                    nodeQ.push(node->right);
                    numSet.insert(node->right->val);
                }
            }
            
        }

    }
    
    bool find(int target) {
        if (numSet.count(target) > 0) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */





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
class FindElements {
public:
    unordered_set<int> numSet;
    FindElements(TreeNode* root) {
        function<void(TreeNode* node, int val)> dfs = [&](TreeNode* node, int val) {
            if (node == nullptr) {
                return ;
            }
            
            numSet.insert(val);            
            node->val = val;
            dfs(node->left, (val << 1) + 1);
            dfs(node->right, (val << 1) + 2);
        };
        dfs(root, 0);
    }
    
    bool find(int target) {
        if (numSet.count(target) > 0) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 
 class FindElements {
private:
    unordered_set<int> valSet;

    void dfs(TreeNode *node, int val) {
        if (node == nullptr) {
            return;
        }
        node->val = val;
        valSet.insert(val);
        dfs(node->left, val * 2 + 1);
        dfs(node->right, val * 2 + 2);
    }

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }

    bool find(int target) {
        return valSet.count(target) > 0;
    }
};



class FindElements {
private:
    TreeNode *root;

public:
    FindElements(TreeNode* root) {
        this->root = root;
        dfs(root, 0);
    }

    void dfs(TreeNode *node, int val) {
        if (node == nullptr) {
            return;
        }
        node->val = val;
        dfs(node->left, val * 2 + 1);
        dfs(node->right, val * 2 + 2);
    }

    bool find(int target) {
        target++;
        int k = 30 - __builtin_clz(target);
        TreeNode *node = root;
        while (k >= 0 && node != nullptr) {
            if ((target & (1 << k)) == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            k--;
        }
        return node != nullptr;
    }
};
