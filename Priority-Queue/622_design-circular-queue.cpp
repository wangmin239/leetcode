class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k;
        index = 0;
        if (size != 0) {
            pQueue = make_unique<int*>(new int[k]);
            ptr = *pQueue.get();
        }
    }
    
    bool enQueue(int value) {
        if (index < size) {
            ptr[index++] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (isEmpty() == true) {
            return false;
        }

        for (int i = 1; i < index; i++) {
            ptr[i - 1] = ptr[i];
        }
        index--;
        return true;
    }
    
    int Front() {
        if (isEmpty() == true) {
            return -1;
        }

        return ptr[0];        
    }
    
    int Rear() {
        if (isEmpty() == true) {
            return -1;
        }

        return ptr[index - 1];
    }
    
    bool isEmpty() {
        if (index == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (index == size) {
            return true;
        }
        return false;
    }

private:
    unique_ptr<int*> pQueue;
    int size;
    int index;
    int* ptr;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
 
 
class MyCircularQueue {
private:
    ListNode *head;
    ListNode *tail;
    int capacity;
    int size;

public:
    MyCircularQueue(int k) {
        this->capacity = k;
        this->size = 0;
        this->head = this->tail = nullptr;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        ListNode *node = new ListNode(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ListNode *node = head;
        head = head->next;  
        size--;
        delete node;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }

    int Rear() {
        if (isEmpty()) {
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



/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
 
class MyCircularQueue {
private:
    int front;
    int rear;
    int capacity;
    vector<int> elements;

public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->elements = vector<int>(capacity);
        rear = front = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return elements[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return elements[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return ((rear + 1) % capacity) == front;
    }
};
