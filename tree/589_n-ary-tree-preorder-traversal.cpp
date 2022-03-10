/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
    void dfs(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        
        auto [val, children] = *root;
        ans.push_back(val);
        
        for (auto child : children) {
            dfs(child, ans);
        }
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        
        while (root != nullptr || st.empty() == false) {
            if (root != nullptr) {
                ans.push_back(root->val);
                while (root->children.empty() == false) {
                    st.push(root->children.back());
                    root->children.pop_back();
                }
                root = nullptr;
            } else {
                root = st.top();
                st.pop();
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    void helper(const Node* root, vector<int> & res) {
        if (root == nullptr) {
            return;
        }
        res.emplace_back(root->val);
        for (auto & ch : root->children) {
            helper(ch, res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        unordered_map<Node *, int> cnt;
        stack<Node *> st;
        Node * node = root;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                st.emplace(node);
                if (node->children.size() > 0) {
                    cnt[node] = 0;
                    node = node->children[0];
                } else {
                    node = nullptr;
                }         
            }
            node = st.top();
            int index = (cnt.count(node) ? cnt[node] : -1) + 1;
            if (index < node->children.size()) {
                cnt[node] = index;
                node = node->children[index];
            } else {
                st.pop();
                cnt.erase(node);
                node = nullptr;
            }
        }
        return res;
    }
};
