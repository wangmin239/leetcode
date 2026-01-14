/* Original Solution */
class Allocator {
public:
    Allocator(int n) {
        arr.resize(n);
        fill(arr.begin(), arr.end(), 0);
    }
    
    int allocate(int size, int mID) {
        int left, right;
        bool isValid = false;
        
        /* Using double pointers to find the partition which meets the requirements */
        for (left = 0, right = 0; right < arr.size(); right++) {
            if (arr[right] == 0) {
                if (right - left == size - 1) {
                    isValid = true;
                    fill_n(arr.begin() + left, size, mID);
                    break;
                }
            } else {
                /* Find the first element whose value is equal zero */
                while (right < arr.size() && arr[right] != 0) {
                    ++right;
                }
                left = right--;
            }
        }
        
        return isValid ? left : -1;
    }
    
    /* statistic the number of the element's value is mID */
    int freeMemory(int mID) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == mID) {
                arr[i] = 0;
                ++cnt;
            }
        }
        
        return cnt;
    }
    vector<int> arr;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
 
 
 
/* Official Solution */ 
 class Allocator {
public:
    Allocator(int n): n(n), memory(n) {}
    
    int allocate(int size, int mID) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (memory[i]) {
                count = 0;
            }
            else {
                ++count;
                if (count == size) {
                    for (int j = i - count + 1; j <= i; ++j) {
                        memory[j] = mID;
                    }
                    return i - count + 1;
                }
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (memory[i] == mID) {
                ++count;
                memory[i] = 0;
            }
        }
        return count;
    }

private:
    int n;
    vector<int> memory;
};
/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
 
 
 