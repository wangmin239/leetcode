class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        vector<int> ans;
        int i = 0;
        while (head != nullptr) {
            ans.push_back(0);
            while (!st.empty() && st.top().first < head->val) {
                auto[_, idx] = st.top();
                ans[idx] = head->val;
                st.pop();
            }
            st.push(make_pair(head->val, i));
            head = head->next;
            i++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> a, stk;
        int i = 0;
        while (head != nullptr) {
            a.push_back(head->val);
            while (!stk.empty() && a[stk.back()] < a[i]) {
                a[stk.back()] = a[i];
                stk.pop_back();
            }
            stk.push_back(i++);
            head = head->next;
        }
        for (int &j: stk) a[j] = 0;
        return move(a);
    }
};

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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> s;

        ListNode* cur = head;
        int idx = -1;
        while (cur) {
            ++idx;
            ans.push_back(0);
            while (!s.empty() && s.top().first < cur->val) {
                ans[s.top().second] = cur->val;
                s.pop();
            }
            s.emplace(cur->val, idx);
            cur = cur->next;
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        
        for (auto *cur = head; cur != nullptr; cur = cur->next) {
            auto *p = cur->next;
            while (p != nullptr) {
                if (p->val > cur->val) {
                    ans.push_back(p->val);
                    break;
                }
                p = p->next;
            }
            if (p == nullptr) {
                ans.push_back(0);
            }
        }
        return ans;
    }
};