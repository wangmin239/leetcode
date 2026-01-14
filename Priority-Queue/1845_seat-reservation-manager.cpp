class SeatManager {
public:
    vector<int> available;

    SeatManager(int n) {
        for (int i = 1; i <= n; ++i){
            available.push_back(i);
        }
    }
    
    int reserve() {
        pop_heap(available.begin(), available.end(), greater<int>());
        int tmp = available.back();
        available.pop_back();
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        available.push_back(seatNumber);
        push_heap(available.begin(), available.end(), greater<int>());
    }
};


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */



class SeatManager {
public:
    SeatManager(int n) {
        uniqPtr = make_unique<int[]>(n + 1);
        int* ptr = uniqPtr.get();

        fill(ptr, ptr + n + 1, 0);
        curId = 1;
        total = n + 1;
    }
    
    int reserve() {
        auto ptr = uniqPtr.get();

        
        while (curId < total) {
            if (ptr[curId] == 0) {
                ptr[curId] = 1;
                break;
            }
            ++curId;
        }
        
        return curId;
    }
    
    void unreserve(int seatNumber) {
        auto ptr = uniqPtr.get();
        ptr[seatNumber] = 0;
        
        curId = min(curId, seatNumber);
    }
    
    unique_ptr<int[]> uniqPtr;
    int curId, total;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */






class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            reserveSeats.push(i);
        }
    }
    
    int reserve() {
        int seatId = reserveSeats.top();
        reserveSeats.pop();
        return seatId;
    }
    
    void unreserve(int seatNumber) {
        reserveSeats.push(seatNumber);
    }
    
    priority_queue<int, vector<int>, greater<int>> reserveSeats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */