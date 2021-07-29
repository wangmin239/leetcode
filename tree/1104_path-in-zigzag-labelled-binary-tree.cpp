

TreeNode* buildTree(int label) {
    int index = 1;
    bool leftToRight;
    stack<TreeNode*> st;
    bool finishBuild = false;
    
    TreeNode* root = new TreeNode(index);
    st.push(root);
    leftToRight = true;
    while (index < label) {
        stack<TreeNode*> tmpSt;
        while (st.empty() != true) {
            if (leftToRight == true) {
                auto parent = st.top();
                st.pop();
                
                parent->right = new TreeNode (++index);
                tmpSt.push(parent->right);
                if (index < label) {
                    parent->left = new TreeNode (++index);
                    tmpSt.push(parent->left);
                } else {
                    finishBuild = true;
                    break;
                }
            } else {
                auto parent = st.top();
                st.pop();
                
                parent->left = new TreeNode (++index);
                tmpSt.push(parent->left);
                if (index < label) {
                    parent->right = new TreeNode (++index);
                    tmpSt.push(parent->right);
                } else {
                    finishBuild = true;
                    break;
                }  
            }
        }
        if (finishBuild == true || index == label) {
            return root;
        }
        leftToRight = !leftToRight;
        st = move(tmpSt);
    }
    return root;
}


void destroyTree(TreeNode* root) {
    queue<TreeNode*> que;
    
    if (root != nullptr) {
        que.push(root);
    }
    
    int size = que.size();
    while (size > 0) {
        while (size > 0) {
            auto parent = que.front();
            que.pop();
            
            auto [val, left, right] = *parent;
            
            if (left != nullptr) {
                que.push(left);
            }
            
            if (right != nullptr) {
                que.push(right);
            }
            
            --size;
            delete parent;
            parent = nullptr;
        }
        size = que.size();
    }
}

class Solution {
public:
    bool getPath(const TreeNode* root, const int label, vector<int>& ans) {
        if (root == nullptr) {
            return false;
        }
        auto [val, left, right] = *root;
        if (val == label) {
            ans.push_back(val);
            return true;
        }
        ans.push_back(val);
        if (getPath(left, label, ans) == true) return true;
        if (getPath(right, label, ans) == true) return true;
        ans.pop_back();
        return false;
    }
        
    vector<int> pathInZigZagTree(int label) {
        TreeNode *root = buildTree(label);
        vector<int> ans;
        
        getPath(root, label, ans);
        destroyTree(root);
        

        return ans;
    }
};




class Solution {
public:
    void getPath(const TreeNode* root, const int label, vector<int>& ans) {
        if (root == nullptr) {
            return ;
        }
        auto [val, left, right] = *root;
        ans.push_back(val);
        getPath(left, label, ans);
    }
        
    vector<int> pathInZigZagTree(int label) {
        TreeNode *root = buildTree(label);
        vector<int> ans;
        
        getPath(root, label, ans);
        return ans;
    }
};


class Solution {
public: 
    vector<int> pathInZigZagTree(int label) {
        int depth = static_cast<int>(log(label) / log(2)) + 1;
        int rowSum = (1 << depth) + (1 << (depth - 1)) -1;
        vector<int> ans(depth);
        
        while (label > 0) {
            ans[--depth] = label;
            label = (rowSum - label) >> 1;
            rowSum >>= 1;
        }
        return ans;
    }
};