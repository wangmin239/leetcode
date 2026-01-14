/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        Node dummyHead(0);
        Node *pre = &dummyHead;
        Node *p = head;
        
        while (p != nullptr) {
            auto node = new Node (p->val);
            nodeMap[p] = node;
            pre->next = node;
            pre = node;            
            p = p->next;
        }
        
        pre = dummyHead.next;
        for (p = head; p != nullptr; p = p->next) {
            if (p->random != nullptr) {
                pre->random = nodeMap[p->random];
            }
            pre = pre->next;
        }
        return dummyHead.next;
    }
};




class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        
        /* interactively insert a duplicate node */
        while (p != nullptr) {
            auto node = new Node (p->val);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        
        /* assign random pointer */      
        for (p = head; p != nullptr; p = p->next) {
            if (p->random != nullptr) {
                auto pNext = p->next;
                pNext->random = p->random->next;
            }
            p = p->next;
        }
        
        /* extract nodes */
        Node dummyHead(0);
        Node *pNew = &dummyHead;
        for (p = head; p != nullptr; p = p->next) {
            pNew->next = p->next;
            pNew = p->next;
            p->next = pNew->next;
            pNew->next = nullptr;
        }
        
        return  dummyHead.next;
    }
};