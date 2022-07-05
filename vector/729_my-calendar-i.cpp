class MyCalendar {
    set<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};



/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


class MyCalendar {
    vector<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                return false;
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */



class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if (isInRange(start, end) == true) {
            return false;
        }
        
        stampMap.emplace(start, end);
        return true;
    }
    
    
private:
    unordered_map<int, int> stampMap;
    
    inline bool isInRange(int left, int right) {
         for (const auto& [start, end] : stampMap) {
            if (start >= left && start < right) {
                return true;
            }
            
            if (end > left && end < right) {
                return true;
            }
            
            if (left >= start && left < end) {
                return true;
            }
            
            if (right > start && right < end) {
                return true;
            }           
        }
        return false;       
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */