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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
        
    }
    
    void dfs(vector<int>& ans, Node* root) {
        if (root == nullptr) {
            return ;
        }
        
        auto [val, children] = *root;
        for (const auto& child : children) {
            dfs(ans, child);
        }
        
        ans.push_back(val);
        
    }
};



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
    void helper(const Node* root, vector<int> & res) {
        if (root == nullptr) {
            return;
        }
        for (auto & ch : root->children) {
            helper(ch, res);
        }
        res.emplace_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};


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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        unordered_map<Node *, int> cnt;
        stack<Node *> st;
        Node * node = root;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.emplace(node);
                if (node->children.size() > 0) {
                    cnt[node] = 0;
                    node = node->children[0];
                } else {
                    node = nullptr;
                }         
            }
            node = st.top();
            int index = cnt.count(node) ? (cnt[node] + 1) : 0;
            if (index < node->children.size()) {
                cnt[node] = index;
                node = node->children[index];
            } else {
                res.emplace_back(node->val);
                st.pop();
                cnt.erase(node);
                node = nullptr;
            }
        }
        return res;
    }
};
