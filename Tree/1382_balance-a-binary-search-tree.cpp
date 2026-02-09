/**
 * Original Solution 1
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> incrVec;
        stack<TreeNode*> st;

        /* Generate the ascending order */
        while (root != nullptr || st.empty() == false) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
                continue;
            }

            root = st.top();

            st.pop();
            incrVec.push_back(root->val);
            root = root->right;     
        }

        int n = incrVec.size();
        auto buildTree = [&incrVec, n](int start, int end, auto&& self) ->TreeNode* {
            if (end < start) {
                return nullptr;
            }

            int mid = (start + end + 1) / 2;
            auto node = new TreeNode(incrVec[mid]);
            node->left = self(start, mid - 1, self);
            node->right = self(mid + 1, end, self);
            return node;
        };

        return buildTree(0, n - 1, buildTree);
    }
};



/**
 * Original Solution 1
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> incrVec;
        auto dfs = [&incrVec](TreeNode* node, auto&& self) {
            if (node == nullptr) {
                return;
            }
            self(node->left, self);
            incrVec.push_back(node->val);
            self(node->right, self);
        };

        /* Generate the ascending order */
        dfs(root, dfs);

        int n = incrVec.size();
        auto buildTree = [&incrVec, n](int start, int end, auto&& self) ->TreeNode* {
            if (end < start) {
                return nullptr;
            }

            int mid = (start + end) / 2;
            auto node = new TreeNode(incrVec[mid]);
            node->left = self(start, mid - 1, self);
            node->right = self(mid + 1, end, self);
            return node;
        };

        return buildTree(0, n - 1, buildTree);
    }
};


/**
 * Official Solution 1
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
    vector<int> inorderSeq;

    void getInorder(TreeNode* o) {
        if (o->left) {
            getInorder(o->left);
        }
        inorderSeq.push_back(o->val);
        if (o->right) {
            getInorder(o->right);
        }
    }

    TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode* o = new TreeNode(inorderSeq[mid]);
        if (l <= mid - 1) {
            o->left = build(l, mid - 1);
        }
        if (mid + 1 <= r) {
            o->right = build(mid + 1, r);
        }
        return o;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
};


/**
 * Official Solution 2
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
    // 94. 二叉树的中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // lambda 递归
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (node == nullptr) {
                return;
            }
            dfs(node->left);          // 左
            ans.push_back(node->val); // 根（这行代码移到前面就是前序，移到后面就是后序）
            dfs(node->right);         // 右
        };

        dfs(root);
        return ans;
    }

    // 108. 将有序数组转换为二叉搜索树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 把 nums[left] 到 nums[right-1] 转成平衡二叉搜索树
        auto dfs = [&](this auto&& dfs, int left, int right) -> TreeNode* {
            if (left == right) {
                return nullptr;
            }
            int m = left + (right - left) / 2;
            return new TreeNode(nums[m], dfs(left, m), dfs(m + 1, right));
        };

        return dfs(0, nums.size());
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        auto nums = inorderTraversal(root);
        return sortedArrayToBST(nums);
    }
};
