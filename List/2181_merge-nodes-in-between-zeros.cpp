


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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(-1, head);
        ListNode* pre = &dummy;
        int sum = head->val;

        for (ListNode* p = head->next; p != nullptr; p = p->next) {
            if (p->val == 0) {
                head->val = sum;
                pre = head;
                head = head->next;
                sum = 0;
            }
            sum += p->val;
        }
        pre->next = nullptr;
        return dummy.next;;
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(-1);
        ListNode* np = &dummy;
        int sum = head->val;

        for (ListNode* p = head->next; p != nullptr; p = p->next) {
            if (p->val == 0) {
                ListNode* node = new ListNode(sum);
                np->next = node;
                np = node;
                sum = 0;
            }
            sum += p->val;
        }
        
        return dummy.next;
    }
};