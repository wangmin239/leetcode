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
    ListNode* oddEvenList(ListNode* head) {
        ListNode  evenList;
        ListNode  *peven = &evenList;
        ListNode  *p = head;
        ListNode  *pre = p;
        if (head == nullptr) {
            return head;
        }
        while (p != nullptr && p->next != nullptr) {
            peven->next = p->next;
            peven = peven->next;
            p->next = peven->next;
            peven->next = nullptr;
            pre = p;
            p = p->next;
        }

        if (p == nullptr) {
            pre->next = evenList.next;
        } else {
            p->next = evenList.next;
        }
        return head;
    }
};



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};