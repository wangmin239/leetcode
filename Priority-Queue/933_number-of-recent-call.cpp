
class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};
/*
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */




class RecentCounter {
private:
    vector<int> prefixSum;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        prefixSum.emplace_back(t);
        auto iter = lower_bound(prefixSum.begin(), prefixSum.end(), t - 3000);
        
        return prefixSum.end() - iter;

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */



class RecentCounter {
private:
    vector<int> prefixSum;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        prefixSum.emplace_back(t);
        auto iter = lower_bound(prefixSum.begin(), prefixSum.end(), t - 3000);
        
        return prefixSum.end() - iter;

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */




class RecentCounter {
private:
    vector<int> prefixSum;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        prefixSum.push_back(t);
        int index;
        int size = prefixSum.size();
        for (index = size; index >= 0; index--) {
            if (t - prefixSum[index] > 3000) {
                    break;
            }
        }
        return size - index;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */