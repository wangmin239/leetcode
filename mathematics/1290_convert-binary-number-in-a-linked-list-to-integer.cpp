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
 
 /* Original Solution 1 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* reverse = nullptr;
        ListNode* p = nullptr;
        int value = 0;
        int i = 0;

        /* reverse the original list */
        while (head != nullptr) {
            p = head;
            head = head->next;
            p->next = reverse;
            reverse = p;
        }

        /* from the lowest bit to the highest bit */
        while (reverse != nullptr) {
            value += (reverse->val << i++);
            reverse = reverse->next;
        }
        
        return value;
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
 
 /* Original Solution 2 */ 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int value = 0;
        
        while (head != nullptr) {
            value = (value << 1) + head->val;
            head = head->next;
        }
        
        return value;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
    }
};
