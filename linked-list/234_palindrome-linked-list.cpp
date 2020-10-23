/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid = nullptr;
        getMid(head, &mid);
        if (mid == nullptr) {
            return true;
        }
        reverseList(&mid);
        return compList(head, mid);

    }

    void getMid(ListNode *head, ListNode **mid) {
        ListNode *slow, *fast, *pre;
        ListNode dummyHead;
        dummyHead.next = head;
        slow = fast = head;
        pre = &dummyHead;
        while(fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        *mid = fast == nullptr ? slow : slow->next;
        pre->next = nullptr;
        return;
    }


    void reverseList(ListNode **head) {
        ListNode dummyHead;
        ListNode *p = *head;

        while (p != nullptr) {
            *head = p->next;
            p->next = dummyHead.next;
            dummyHead.next = p;
            p = *head;
        }
        *head = dummyHead.next;
    }

    bool compList(ListNode *list1, ListNode *list2) {
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val == list2->val) {
                list1 = list1->next;
                list2 = list2->next;
            } else {
                break;
            }
        }
        return list1 == nullptr && list2 == nullptr;
    }
};