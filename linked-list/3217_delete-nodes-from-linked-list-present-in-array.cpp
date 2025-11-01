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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode  dummy(-1, head), list;
        unordered_set<int> target(nums.begin(), nums.end());
        ListNode* pre = &dummy;
        ListNode* ptr = &list;

        for (ListNode *cur = head; cur != nullptr; cur = pre->next) {
            if (target.count(cur->val) != 0) {
                pre = cur;
                continue;
            }
            /* remove the current node from the original list */
            pre->next = cur->next;

            /* the current node points to the new list tail */
            cur->next = ptr->next;
            ptr->next = cur;
            ptr = cur;


        }

        return list.next;
    }
};


/* Official Solution 2 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        while (cur->next) {
            ListNode* nxt = cur->next;
            if (st.contains(nxt->val)) {
                cur->next = nxt->next; // 从链表中删除 nxt 节点
            } else {
                cur = nxt; // 不删除 nxt，继续向后遍历链表
            }
        }
        return dummy.next;
    }
};
