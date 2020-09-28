class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            vector<TreeNode*> p_st;
            vector<TreeNode*> q_st;
            getPath(root, p, p_st);
            getPath(root, q, q_st);
            auto i = 0;
            auto len = min(p_st.size(), q_st.size());
            for (; i < len; ++i) {
                if (p_st[i] != q_st[i]) {
                    break;
                }
            }
            return p_st[i-1];
    }

    bool getPath(TreeNode* t, TreeNode* wanted, vector<TreeNode*>& st)
    {
        if (t == nullptr) {
            return false;
        }
        if (t == wanted) {
            st.emplace_back(t);
            return true;
        }

        auto [val, left, right] = *t;
        st.emplace_back(t);
        if (getPath(left, wanted, st) == true) {
            return true;
        } 
 
        if (getPath(right, wanted, st) == true) {
            return true;
        }
        st.pop_back();         
        return false;
    }

    TreeNode* getParent(TreeNode* t, TreeNode* wanted)
    {
        if (t == nullptr || t == wanted) {
            return t;
        }

        auto [val, left, right] = *t;
        if (wanted == left || wanted == right) {
            return t;
        }
        auto lparent = getParent(left, wanted);
        auto rparent = getParent(right, wanted);
        auto parent = lparent == nullptr ? rparent : lparent;
        return parent;
    }    
};