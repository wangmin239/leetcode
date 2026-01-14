class Solution {
private:
    void dfsBuild(ListNode*& li, TreeNode* root){
        if (root == NULL)
            return;
        dfsBuild(li, root->left);
        root->val = li->val;
        li = li->next;
        dfsBuild(Dli, root->right);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* node = head;
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> que;
        que.push(root);
        node = node->next;
        while (node){
            TreeNode* n = que.front();
            que.pop();
            n->left = new TreeNode(0);
            que.push(n->left);
            node = node->next;
            if (node == NULL){
                break;
            }
            n->right = new TreeNode(0);
            que.push(n->right);
            node = node->next;
        }
        dfsBuild(head, root);
        return root;
    }
};


class Solution {
private:
    vector<int> v;
    TreeNode* fun(int L, int R){
        if (L > R)
            return nullptr;
        int center = (L + R) / 2;
        return L == R ? new TreeNode(v[center]) : new TreeNode(v[center], fun(L, center - 1), fun(center + 1, R));
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        for (ListNode* p = head; p; p = p->next)
            v.push_back(p->val);
        return fun(0, v.size() - 1);
    }
};