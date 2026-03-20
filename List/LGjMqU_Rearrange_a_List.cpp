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
    void reorderList(ListNode* head) {
        ListNode dummy;
        ListNode* pre = head;
        ListNode* p = head;
        ListNode* post = head;

        /* get the middle node of the list */
        while(post != nullptr && post->next != nullptr) {
            pre = p;
            p = p->next;
            post = post->next->next;
        }

        if (p == post) {
            return;
        }

        pre->next = nullptr;
        ListNode* mid = p;


        /* Reverse the latter half of the linked list */
        while (mid != nullptr) {
            mid = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = mid;
        }
        /* Merge the two lists in an interleaved manner */
        for (p = head, mid = dummy.next; p != nullptr; mid = p, p = post) {
            post = p->next;
            p->next = mid;
            p = mid->next;
            mid->next = post;
            pre = mid;
        }

        if (mid != nullptr) {
            pre->next = mid;
        }

        return ;
    }
};



/* Official Solution 1 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};



/* Official Solution 2 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};



/* Official Solution 3 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* dummmy = new ListNode(0);
        dummmy->next = head;
        ListNode* slow = dummmy;
        ListNode* fast = dummmy;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        delete dummmy;
        dummmy = nullptr;
        ListNode* headB = slow->next;
        slow->next = nullptr;
        ListNode* p2 = reverseList(headB);
        ListNode* p1 = head;
        ListNode* p3 = nullptr;
        while (p2 != nullptr) {
            p3 = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = p3;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* left = nullptr;
        ListNode* cur = head;
        ListNode* right = nullptr;
        while (cur != nullptr) {
            right = cur->next;
            cur->next = left;
            left = cur;
            cur = right;
        }
        return left;
    }
};


/* Official Solution 4 */
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. 找到链表的中间节点（前半部分的最后一个节点）
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 将链表从中间断开，并反转后半部分
        ListNode *mid = slow;
        ListNode *second = mid->next; // 后半部分的头
        mid->next = nullptr;          // 断开前后

        // 反转后半部分
        ListNode *prev = nullptr;
        ListNode *curr = second;
        while (curr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode *secondHead = prev; // 反转后的后半部分头

        // 3. 合并两个链表：L0 -> Ln -> L1 -> Ln-1 -> ...
        ListNode *first = head;
        ListNode *secondList = secondHead;
        while (first && secondList) {
            ListNode *firstNext = first->next;
            ListNode *secondNext = secondList->next;

            first->next = secondList;
            secondList->next = firstNext;

            first = firstNext;
            secondList = secondNext;
        }
    }
};