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
        ListNode dummy(0, head);
        ListNode* mid;
        ListNode* slow = &dummy;

        for  (ListNode *fast = slow = &dummy; slow != nullptr && fast != nullptr;) {
            fast = fast->next;
            if (fast == nullptr) {
                mid = slow;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        /* revert the bottom half list */
        ListNode bottom;
        for (ListNode* p = mid->next; p != nullptr; ) {
            ListNode* node = p;
            p = p->next;
            node->next = bottom.next;
            bottom.next = node;
        }
        mid->next = nullptr;
        
        /* rearrange the list */ 
        for (ListNode* p = bottom.next; p != nullptr;) {
            ListNode* node = p;
            p = p->next;
            node->next = head->next;
            head->next = node;
            head = node->next;
        }
        head = dummy.next;
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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodeVec;
        
        for (ListNode* p = head; p != nullptr; p = p->next) {
            nodeVec.push_back(p);
        }
        
        int n = nodeVec.size();
        int left = 0;
        int right = n - 1;
        ListNode dummyHead;
        ListNode* p = &dummyHead;
        while (left < right) {
            p->next = nodeVec[left++];
            p = p->next;
            p->next = nodeVec[right--];
            p = p->next;
        }
        if (n % 2 == 1) {
            p->next = nodeVec[left];
            p = p->next;
        }
        p->next = nullptr;
        head = dummyHead.next;
    }
};