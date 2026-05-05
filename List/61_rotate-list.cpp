/* Original Solution 1 */
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode reverseHead;
        ListNode* p = head;
        ListNode* post;
        
        while (p != nullptr) {
            post = p->next;
            p->next = reverseHead.next;
            reverseHead.next = p;
            p = post;
            ++len;
        }
        
        if (len == 0) {
            return head;
        }
        
        k %= len;
        
        ListNode dummy;
        p = post = reverseHead.next;       
        while (k--) {
            post = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = post;
        }

        ListNode* pre = &dummy;
        for (p = dummy.next; p != nullptr;) {
            pre = p;
            p = p->next;
        }
        
        while(post != nullptr) {
            p = post;
            post = post->next;
            p->next = pre->next;
            pre->next = p;    
        }
        return dummy.next;
    }
};

/* Official Solution 1 */
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n) {
            return head;
        }
        iter->next = head;
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};
