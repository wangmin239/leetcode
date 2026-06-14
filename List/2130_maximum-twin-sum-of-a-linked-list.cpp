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
    int pairSum(ListNode* head) {
        auto getMidNode = [](ListNode* head) {
            ListNode *slow, *fast;

            for (slow = fast = head; fast != nullptr && fast->next != nullptr; ) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        };

        auto reverseHalf = [](ListNode* head, ListNode* tail) {
            ListNode *front = nullptr;

            for (ListNode* p = head; p != tail;) {
                p = p->next;
                head->next = front;
                front = head;
                head = p;
            }

            return front;
        };

        auto midNode = getMidNode(head);
        auto front = reverseHalf(head, midNode);

        int ans = 0;

        while (midNode != nullptr) {
            ans = max(ans, midNode->val + front->val);
            midNode = midNode->next;
            front = front->next;
        }

        return ans;
    }
};

/**
 * Original Solution 2
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
    int pairSum(ListNode* head) {
        int nodeCnt = 0;
        auto getMidNode = [&nodeCnt](ListNode* head) {
            ListNode *slow, *fast;

            for (slow = fast = head; fast != nullptr && fast->next != nullptr; ) {
                slow = slow->next;
                fast = fast->next->next;
                ++nodeCnt;
            }

            return slow;
        };

        auto midNode = getMidNode(head);
        vector<int> arr(nodeCnt);
        int ans = 0;
        int i = 0;
        for (ListNode* p = head; p != midNode; p = p->next) {
            arr[i++] = p->val;
        }

        i = 0;
        for (ListNode* p = midNode; p != nullptr; p = p->next, ++i) {
            ans = max(ans, arr[nodeCnt - i - 1] + p->val);
        }

        return ans;
    }
};


/**
 * Original Solution 3
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
    int pairSum(ListNode* head) {
        int nodeCnt = 0, ans = 0;
        vector<int> valArr;

        for (ListNode *p = head; p != nullptr; p = p->next) {
            valArr.push_back(p->val);
        }

        nodeCnt = valArr.size() / 2;
        for (int i = 0; i < nodeCnt; i++) {
            ans = max(ans, valArr[nodeCnt + i] + valArr[nodeCnt - i - 1]);
        }


        return ans;
    }
};



/**
 * Official Solution 3
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转链表
        ListNode* last = slow->next;
        while (last->next) {
            ListNode* cur = last->next;
            last->next = cur->next;
            cur->next = slow->next;
            slow->next = cur;
        }
        int ans = 0;
        ListNode* x = head;
        ListNode* y = slow->next;
        while (y) {
            ans = max(ans, x->val + y->val);
            x = x->next;
            y = y->next;
        }
        return ans;
    }
};


/**
 * Official Solution 4
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
    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* left = head;

        auto dfs = [&](this auto&& dfs, ListNode* right) -> void {
            // 「递」，先把 right 移到链表末尾
            if (right->next) {
                dfs(right->next);
            }
            // 「归」的过程就是在从右到左遍历链表
            ans = max(ans, left->val + right->val);
            left = left->next; // left 往右走
            // 归，right 会往左走
        };

        dfs(head);
        return ans;
    }
};
