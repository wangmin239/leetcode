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
private:
    unordered_map<int, TreeNode*> parentMap;
    vector<int> ans;
public:
    void findParent(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        auto [val, left, right] = *root;
        if (left != nullptr) {
            parentMap[left->val] = root;
            findParent(left);
        }
        
        if (right != nullptr) {
            parentMap[right->val] = root;
            findParent(right);
        }
    }
    
    void getDepth(TreeNode* target, TreeNode* from, int depth, int k) {
        if (target == nullptr) {
            return;
        }
        
        auto [val, left, right] = *target;
        if (depth == k) {
            ans.push_back(val);
            return;
        }
        
        if (left != from) {
            getDepth(left, target, depth + 1, k);
        }
        
        if (right != from) {
            getDepth(right, target, depth + 1, k);
        }
        
        if (parentMap[val] != from) {
            getDepth(parentMap[val], target, depth + 1, k);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        getDepth(target, nullptr, 0, k);
        return ans;
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parentMap;
        vector<int> ans;
        auto getParents = [&] (auto&& getParents, TreeNode* node) -> void {
            if (node == nullptr) {
                return;
            }
            auto [val, left, right] = *node;
            if (left != nullptr) {
                parentMap[left->val] = node;
                getParents(getParents, left);
            }
            
            if (right != nullptr) {
                parentMap[right->val] = node;
                getParents(getParents, right);
            }
            return;
        };
        
        auto getDepth = [&](auto&& getDepth, TreeNode* node, TreeNode* from, int depth, int k) -> void {
            if (node == nullptr) {
                return;
            }
            
            auto [val, left, right] = *node;
            
            if (depth == k) {
                ans.push_back(val);
                return;
            }
            
            if (left != from) {
                getDepth(getDepth, left, node, depth + 1, k);
            }
            
            if (right != from) {
                getDepth(getDepth, right, node, depth + 1, k);
            }
            
            if (parentMap[node->val] != from) {
                getDepth(getDepth, parentMap[node->val], node, depth + 1, k);
            }
        };
        
        getParents(getParents, root);
        getDepth(getDepth, target, nullptr, 0, k);
        return ans;
    }
};