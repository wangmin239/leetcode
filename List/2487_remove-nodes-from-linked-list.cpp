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
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        head->next = removeNodes(head->next);
        if (head->next != nullptr && head->val < head->next->val) {
            return head->next;
        } else {
            return head;
        }
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode *> st;
        for (; head != nullptr; head = head->next) {
            st.push(head);
        }
        for(; !st.empty(); st.pop()) {
            if (head == nullptr || st.top()->val >= head->val) {
                st.top()->next = head;
                head = st.top();
            }
        }
        return head;
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
    ListNode *reverse(ListNode *head) {
        ListNode dummy;
        while (head != nullptr) {
            ListNode *p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        for (ListNode *p = head; p->next != nullptr; ) {
            if (p->val > p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return reverse(head);
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        
        for (ListNode* p = head; p != nullptr; p = p->next) {    
            while (st.empty() == false) {
                auto node = st.top();
                if (node->val < p->val) {
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(p);
        }
        
        ListNode* dummyHead;
        while (st.empty() == false) {
            auto node = st.top();
            st.pop();
            node->next = dummyHead.next;
            dummyHead.next = node;
        }
        return dummyHead.next;
    }
};