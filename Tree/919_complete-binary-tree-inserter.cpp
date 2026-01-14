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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root = root;
        _que.push(root);

        while (_que.empty() == false) {
            int size = _que.size();
            bool lastLayer = false;
            while (size != 0) {
                auto node = _que.front();
                auto [val, left, right] = *node;
                
                if (left != nullptr) {
                    _que.push(left);
                }
                
                if (right != nullptr) {
                    _que.push(right);
                }

                if (left != nullptr && right != nullptr) {
                    _que.pop();
                    --size;
                    continue;
                }
                
                lastLayer = true;
                break;
   
            }
            
            if (lastLayer == true) {
                break;
            }
        }
    }
    
    int insert(int val) {
        auto parent = _que.front();
        auto [value, left, right] = *parent;
        auto node = new TreeNode(val);
        
        if (left == nullptr) {
            parent->left = node;
        } else {
            parent->right = node;
            _que.pop();
        }
        
        _que.push(node);
        return value;
    }
    
    TreeNode* get_root() {
        return _root;
    }

private:
    TreeNode* _root;
    queue<TreeNode*> _que;

};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            if (!(node->left && node->right)) {
                candidate.push(node);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* child = new TreeNode(val);
        TreeNode* node = candidate.front();
        int ret = node->val;
        if (!node->left) {
            node->left = child;
        }
        else {
            node->right = child;
            candidate.pop();
        }
        candidate.push(child);
        return ret;
    }
    
    TreeNode* get_root() {
        return root;
    }

private:
    queue<TreeNode*> candidate;
    TreeNode* root;
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
 
 
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            ++cnt;
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    
    int insert(int val) {
        ++cnt;
        TreeNode* child = new TreeNode(val);
        TreeNode* node = root;
        int highbit = 31 - __builtin_clz(cnt);
        for (int i = highbit - 1; i >= 1; --i) {
            if (cnt & (1 << i)) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        if (cnt & 1) {
            node->right = child;
        }
        else {
            node->left = child;
        }
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }

private:
    int cnt = 0;
    TreeNode* root;
};
