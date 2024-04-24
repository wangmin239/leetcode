
class Solution {
public:
    int amountOfTime(TreeNode *root, int start) {
        unordered_map<int, vector<int>> graph;
        function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            for (TreeNode *child : vector<TreeNode *>{node->left, node->right}) {
                if (child != nullptr) {
                    graph[node->val].push_back(child->val);
                    graph[child->val].push_back(node->val);
                    dfs(child);
                }
            }
        };
        dfs(root);
        queue<vector<int>> q;
        q.push({start, 0});
        unordered_set<int> visited;
        visited.insert(start);
        int time = 0;
        while (!q.empty()) {
            auto arr = q.front();
            q.pop();
            int nodeVal = arr[0];
            time = arr[1];
            for (int childVal: graph[nodeVal]) {
                if (!visited.count(childVal)) {
                    q.push({childVal, time + 1});
                    visited.insert(childVal);
                }
            }
        }
        return time;
    }
};







class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (root->val == start) {
            return maxDepth(root) - 1;
        }
        int leftDepth = 0;
        auto leftParent = findParent(root, root->left, start, leftDepth);

        if (leftParent != nullptr) {
            int total = leftDepth + maxDepth(root->right) ;
            if (leftParent->left && leftParent->left->val == start) {
                total = max(max(total, maxDepth(leftParent->right) + 1), maxDepth(leftParent->left) - 1);
            } else {
                total = max(max(total,  maxDepth(leftParent->left) + 1), maxDepth(leftParent->right) - 1);
            }
            return total;
        }

        int rightDepth = 0;
        auto rightParent = findParent(root, root->right, start, rightDepth);
        int total = rightDepth + maxDepth(root->left);

        if (rightParent->left && rightParent->left->val == start) {
            total = max(max(total, maxDepth(rightParent->right) + 1),  maxDepth(rightParent->left) - 1);
        } else {
            total = max(max(total,  maxDepth(rightParent->left) + 1), maxDepth(rightParent->right) - 1);
        }
        return total;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right))+ 1;
    }

    TreeNode* findParent(TreeNode* parent, TreeNode* curNode, int start, int& minutes) {
        if (curNode == nullptr) {
            return nullptr;
        }
        ++minutes;
        if (curNode->val == start) {
            return parent;
        }
        int leftDepth = 0;
        int rightDepth = 0;

        auto leftParent = findParent(curNode, curNode->left, start, leftDepth);
        auto rightParent = findParent(curNode, curNode->right, start, rightDepth);

        if (leftParent == nullptr && rightParent == nullptr) {
            return nullptr;
        }

        if (leftParent == nullptr) {
            minutes += rightDepth;
            return rightParent;
        }

        minutes += leftDepth;
        return leftParent;
    }
};
