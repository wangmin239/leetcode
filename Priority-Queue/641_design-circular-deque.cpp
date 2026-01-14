class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        this->capacity = k;
        this->size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull() == true) {
            return false;
        }
        size++;
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull() == true) {
            return false;
        }
        size++;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty() == true) {
            return false;
        }
        --size;
        dq.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty() == true) {
            return false;
        }
        --size;
        dq.pop_back();
        return true;
    }
    
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return dq.front();
    }
    
    int getRear() {
        if (isEmpty() == true) {
            return -1;
        }
        return dq.back();
    }
    
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (size == capacity) {
            return true;
        }
        return false;
    }
private:
    int capacity;
    int size;
    deque<int> dq;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
 
 ["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]
 
class MyCircularDeque {
private:
    vector<int> elements;
    int rear, front;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        rear = front = 0;
        elements = vector<int>(k + 1);
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        elements[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return elements[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return elements[(rear - 1 + capacity) % capacity];
    }   

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};




struct DLinkListNode {
    int val;
    DLinkListNode *prev, *next;
    DLinkListNode(int _val): val(_val), prev(nullptr), next(nullptr) {

    }
};

class MyCircularDeque {
private:
    DLinkListNode *head, *tail;
    int capacity;
    int size;

public:
    MyCircularDeque(int k): capacity(k), size(0), head(nullptr), tail(nullptr) {
        
    }

    bool insertFront(int value) {
        if (size == capacity) {
            return false;
        }
        DLinkListNode *node = new DLinkListNode(value);
        if (size == 0) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size == capacity) {
            return false;
        }
        DLinkListNode *node = new DLinkListNode(value);
        if (size == 0) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        DLinkListNode *node = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete node;
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        DLinkListNode *node = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        delete node;
        size--;
        return true;
    }

    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->val;
    }

    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
