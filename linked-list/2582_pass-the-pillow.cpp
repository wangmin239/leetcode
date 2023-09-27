class Solution {
public:
    int passThePillow(int n, int time) {
        int turns = time / (n - 1);
        int mod = time % (n - 1) ;
        
        if (turns & 0x1) {
            return mod == 0 ? n : n - mod;
        }
        
        return mod == 0 ? 1 : mod + 1;
    }
};

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
    }
};



class Solution {
public:
    class Node {
        public:
            int val;
            class Node* next;
            Node(int _val) : val(_val), next(nullptr) {}
    };
    
    void initCircle(int n, Node* dummy) {
        Node* head = dummy;
        
        for (int i = 1; i <= n; i++) {
            head->next = new Node(i);
            head = head->next;
        }
        
        for (int i = n - 1; i > 1; i--) {
            head->next = new Node(i);
            head = head->next;
        }
        head->next = dummy->next;
    }
    
    void destroyCircle(int n, Node* dummy) {
        Node* p = dummy->next;
        n = 2 * n - 2;
        while (n-- > 0) {
            dummy->next = p->next;
            delete p;
            p = dummy->next;
        }
        
    }
    
    int passThePillow(int n, int time) {
        Node dummy(0);
        initCircle(n, &dummy);
        Node *p = dummy.next;
        while (time-- > 0) {
            p = p->next;         
        }
        int ans = p->val;
        destroyCircle(n, &dummy);
        return ans;
    }
};





class Solution {
public:
    class Node : public enable_shared_from_this<Node> {
        public:
            int val;
            shared_ptr<Node> next;
            Node(int _val) : val(_val) {}
    };
    
    void initCircle(int n, shared_ptr<Node> head) {
        shared_ptr<Node> ptr = head;
        
        for (int i = 1; i <= n; i++) {
            ptr->next = make_shared<Node>(i);
            ptr = ptr->next;
        }
        
        for (int i = n - 1; i > 1; i--) {
            ptr->next = make_shared<Node>(i);
            ptr = ptr->next;
        }
        ptr->next = head->next;
    }
    
    
    int passThePillow(int n, int time) {
        shared_ptr<Node> head(new Node(0));
        initCircle(n, head);
        shared_ptr<Node> p = head->next;
        while (time-- > 0) {
            p = p->next;         
        }
        int ans = p->val;
        return ans;
    }
};