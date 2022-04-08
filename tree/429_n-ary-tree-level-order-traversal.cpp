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
    vector<vector<int>> levelOrder(Node* root) {
       vector<vector<int>> ans;
       queue<Node*>  levelQue;
       
       if (root == nullptr) {
           return ans;
       }
       
       levelQue.push(root);
       
       while (levelQue.empty() == false) {
           int size = levelQue.size();
           vector<int> levelVals(size, 0);
           
           for (int i = 0; i < size; i++) {
               auto node = levelQue.front();
               auto [val, children] = *node;
               levelVals[i] = val;
               levelQue.pop();
               if (children.empty() == true) {
                   continue;
               }
               
               for (const auto& child : children) {
                   levelQue.push(child);
               }
           }
           ans.push_back(move(levelVals));
       }
       return ans;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> ans(1000);
        int maxHeight = 0;
        function<void(Node*, int)> dfs = [&](Node* node, int h) {
            if(node == nullptr) {
                return;
            }
            maxHeight = max(maxHeight, h);
            ans[h].emplace_back(node->val);
            for(auto& next : node->children) {
                dfs(next, h + 1);
            }
        };
        dfs(root, 0);
        ans.resize(maxHeight + 1);
        return ans;
    }
};