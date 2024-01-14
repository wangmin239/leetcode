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
    ListNode* deleteDuplicates(ListNode* head) {
        
        for (ListNode* curP = head; curP != nullptr; ) {
            ListNode* nextP = curP->next;
            if (nextP != nullptr && curP->val == nextP->val) {
                    curP->next = nextP->next;
            } else {
                curP = curP->next;
            }
        }

        return head;
    }
};