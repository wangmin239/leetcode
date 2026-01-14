/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        auto start = root;
        while (start != nullptr) {
            Node* last = nullptr;
            Node* nextStart = nullptr;
            for (auto p = start; p != nullptr; p = p->next) {
                auto [val, left, right, next] = *p;
                if (left != nullptr) {
                    buildList(last, left, nextStart);
                } 
                if (right != nullptr) {
                    buildList(last, right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
    }

    void buildList(Node* &last, Node* p, Node* &nextStart)
    {
        if (last != nullptr) {
            last->next = p;
        } else {
            nextStart = p;
        }
        last = p;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            auto size = que.size();
            Node dummy(0);
            Node* head = &dummy;
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();
                auto [val, left, right, next] = *node;
                if (left != nullptr)  que.push(left);
                if (right != nullptr) que.push(right);
                head->next = node;
                head = node;
            }
        }
        return root;
    }
};