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
 * Original Solution 1
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;
        auto getNode = [&nodeMap](int val) {
            if (nodeMap.count(val)) {
                return nodeMap[val];
            }

            auto node = new TreeNode(val);
            nodeMap[val] = node;
            return node;
        };

        for (const auto& descript : descriptions) {
            auto parent = getNode(descript.front());
            auto child =  getNode(descript[1]);
            int isLeft = descript.back();

            children.insert(descript[1]);

            if (isLeft) {
                parent->left = child;
            } else {
                parent->right = child;
            }

        }

        TreeNode* root = nullptr;
        for (const auto& descript : descriptions) {
            if (children.count(descript.front()) == 0) {
                root = nodeMap[descript.front()];
                break;
            }
        }

        return root;
    }
};

/* Official Solution 1 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> isRoot;   // 数值对应的节点是否为根节点的哈希表
        unordered_map<int, TreeNode*> nodes;   // 数值与对应节点的哈希表
        for (const auto& d: descriptions) {
            int p = d[0];
            int c = d[1];
            bool left = d[2];
            if (!isRoot.count(p)) {
                isRoot[p] = true;
            }
            isRoot[c] = false;
            // 创建或更新节点
            if (!nodes.count(p)) {
                nodes[p] = new TreeNode(p);
            }
            if (!nodes.count(c)) {
                nodes[c] = new TreeNode(c);
            }
            if (left) {
                nodes[p]->left = nodes[c];
            } else {
                nodes[p]->right = nodes[c];
            }
        }
        // 寻找根节点
        int root = -1;
        for (const auto& [val, r]: isRoot) {
            if (r) {
                root = val;
                break;
            }
        }
        return nodes[root];
    }
};

/* Official Solutin 2 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        nodes.reserve(descriptions.size() + 1); // 预分配空间
        int root = 0;

        for (auto& d : descriptions) {
            int x = d[0], y = d[1];
            if (!nodes.contains(x)) {
                nodes[x] = new TreeNode(x);
                root ^= x;
            }
            if (!nodes.contains(y)) {
                nodes[y] = new TreeNode(y);
                root ^= y;
            }
            if (d[2]) {
                nodes[x]->left = nodes[y];
            } else {
                nodes[x]->right = nodes[y];
            }
            root ^= y;
        }

        return nodes[root];
    }
};
