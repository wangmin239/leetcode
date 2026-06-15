/**
 * Original Solution 1
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *slow, *fast;

        for (slow = fast = head; fast != nullptr && fast->next != nullptr; ) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (pre == nullptr) {
            return pre;
        }
        pre->next = slow->next;

        return head;
    }
};


/**
 * Official Solution 1
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

