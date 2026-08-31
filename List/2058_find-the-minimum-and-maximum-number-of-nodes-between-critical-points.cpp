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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        const int prevLessCur = 0;
        const int prevGreaterCur = 1;
        const int prevEqualCur = -1;

        int curId = 2;
        int prevState;
        int firstPointId = -1;
        int prevPointId = -1;
        int curPointId = -1;
        int minDist = INT_MAX;


        ListNode* prev = head;
        ListNode* cur = head->next;
        auto getCurState = [&](ListNode* prev, ListNode* cur) {
            int curState;

            if (prev->val < cur->val) {
                curState = prevLessCur;
            } else if (prev->val > cur->val) {
                curState = prevGreaterCur;
            } else {
                curState = prevEqualCur;
            }

            return curState;
        };

        prevState = getCurState(prev, cur);

        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
            ++curId;

            int curState = getCurState(prev, cur);

            if (prevState == prevEqualCur || curState == prevEqualCur) {
                prevState = curState;
                continue;
            }

            if (prevState ^ curState) {
                if (firstPointId == -1) {
                    firstPointId = curId;
                    prevPointId = curId;
                }

                curPointId = curId;
                if (curPointId > prevPointId) {
                    minDist = min(minDist, curPointId - prevPointId);
                }
                prevPointId = curPointId;

            }
            prevState = curState;
        }

        if (firstPointId == curPointId) {
            return {-1, -1};
        }

        return {minDist, curPointId - firstPointId};
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

 /* Official Solution 1 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = -1, maxDist = -1;
        int first = -1, last = -1, pos = 0;
        ListNode* cur = head;
        while (cur->next->next) {
            // 获取连续的三个节点的值
            int x = cur->val;
            int y = cur->next->val;
            int z = cur->next->next->val;
            // 如果 y 是临界点
            if (y > max(x, z) || y < min(x, z)) {
                if (last != -1) {
                    // 用相邻临界点的距离更新最小值
                    minDist = (minDist == -1 ? pos - last : min(minDist, pos - last));
                    // 用到第一个临界点的距离更新最大值
                    maxDist = max(maxDist, pos - first);
                }
                if (first == -1) {
                    first = pos;
                }
                // 更新上一个临界点
                last = pos;
            }
            cur = cur->next;
            ++pos;
        }
        return {minDist, maxDist};
    }
};

