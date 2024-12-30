class Solution {
    bool dfs(TreeNode* rt, ListNode* head) {
        // 链表已经全部匹配完，匹配成功
        if (head == NULL) return true;
        // 二叉树访问到了空节点，匹配失败
        if (rt == NULL) return false;
        // 当前匹配的二叉树上节点的值与链表节点的值不相等，匹配失败
        if (rt->val != head->val) return false;
        return dfs(rt->left, head->next) || dfs(rt->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return [h = head](this auto&& f, auto head, auto root, TreeNode* l = nullptr, TreeNode* r = nullptr)->bool { 
            return !head
                 || root && head->val == root->val && (f(head->next, root->left) || f(head->next, root->right)) 
                 || l && f(h, l, l->left, l->right)
                 || r && f(h, r, r->left, r->right);
        }(head, root, root->left, root->right);
    }
};



class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true; // 链表为空，说明已经匹配完成
        }
        if (root == nullptr) {
            return false; // 树为空，无法继续匹配
        }

        // 尝试匹配当前节点
        if (match(head, root)) {
            return true;
        }

        // 如果当前节点匹配失败，则从左右子树开始继续匹配
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool match(ListNode* head, TreeNode* root) {
        // 链表为空，说明已经匹配完成
        if (head == nullptr) {
            return true;
        }
        // 树为空，无法继续匹配
        if (root == nullptr) {
            return false;
        }
        // 如果当前节点值匹配，则继续匹配下一个节点
        if (head->val == root->val) {
            return match(head->next, root->left) ||
                   match(head->next, root->right);
        }
        // 当前节点值不匹配，则匹配失败
        return false;
    }
};

class Solution {
    ListNode lHead;
    boolean isSubPath;
    public boolean isSubPath(ListNode head, TreeNode root) {
        lHead = head;
        traverse(root);
        return isSubPath;
    }

    private void traverse(TreeNode root) {
        if (root == null || isSubPath) return;
        if (hasCommonPath(root, lHead)) {
            isSubPath = true;
            return;
        }
        traverse(root.left);
        traverse(root.right);
    }

    private boolean hasCommonPath(TreeNode p, ListNode q) {
        if (p == null || q == null) {
            if (p == null && q != null) return false;
            return true;
        }
        return p.val == q.val && (hasCommonPath(p.left, q.next) || hasCommonPath(p.right, q.next));
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root, st, head);
    }
    bool dfs(ListNode* curNode, TreeNode* root,  stack<ListNode*>& st, ListNode* head) {
        if (curNode != nullptr && root == nullptr) {
            return false;
        }
        
        if (curNode != nullptr && root != nullptr) {
            if (root->val == curNode->val) {
                st.push(curNode);
                return dfs(curNode->next, root->left, st, head) || dfs(curNode->next, root->right, st, head);
            }
            
            if (st.empty() != true) {
                auto preNode = st.top();
                st.pop();
                return dfs(preNode,root, st, head);
            } else {
                return dfs(head, root->left, st, head) || dfs(head, root->right, st, head);
            }
        }
        
        return true;
    }    
    stack<ListNode*> st;
};