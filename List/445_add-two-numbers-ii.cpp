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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
        ListNode dummy;
        int cry = 0;

        while (head1 != nullptr || head2 != nullptr) {
            int sum = cry;

            if (head1 != nullptr) {
                sum += head1->val;
                head1 = head1->next;
            }
            
            if (head2 != nullptr) {
                sum += head2->val;
                head2 = head2->next;
            }
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;    
        }
        

        if (cry != 0 ) {
            ListNode* node = new ListNode(cry, dummy.next);
            dummy.next = node;
        }
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode dummy;
        ListNode* curP = head;
        
        while (curP != nullptr) {
            ListNode* prev = curP;
            curP = curP->next;
            prev->next = dummy.next;
            dummy.next  = prev;
        }
        
        return dummy.next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        ListNode dummy;
        int cry = 0;
        
        parseList(l1, st1);
        parseList(l2, st2);

        while (st1.empty() == false && st2.empty() == false) {
            int sum = st1.top() + st2.top() + cry;
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;
            st1.pop();
            st2.pop();    
        }
        
        while (st1.empty() == false) {
            int sum = st1.top() + cry;
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;
            st1.pop();
        }
        
        while (st2.empty() == false) {
            int sum = st2.top() + cry;
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;
            st2.pop();
        }
        
        if (cry != 0 ) {
            ListNode* node = new ListNode(cry, dummy.next);
            dummy.next = node;
        }
        return dummy.next;
    }
    
    void parseList(ListNode* list, stack<int>& st) {
        while (list != nullptr) {
            st.push(list->val);
            list = list->next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
        ListNode dummy;
        int cry = 0;

        while (head1 != nullptr && head2 != nullptr) {
            int sum = head1->val + head2->val + cry;
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;
            head1 = head1->next;
            head2 = head2->next;    
        }
        
        while (head1 != nullptr) {
            int sum = head1->val + cry;
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;
            head1 = head1->next;
        }
        
        while (head2 != nullptr) {
            int sum = head2->val + cry;
            cry = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy.next);
            dummy.next = node;
            head2 = head2->next;
        }
        
        if (cry != 0 ) {
            ListNode* node = new ListNode(cry, dummy.next);
            dummy.next = node;
        }
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode dummy;
        ListNode* curP = head;
        
        while (curP != nullptr) {
            ListNode* prev = curP;
            curP = curP->next;
            prev->next = dummy.next;
            dummy.next  = prev;
        }
        
        return dummy.next;
    }
};