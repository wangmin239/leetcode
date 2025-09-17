/* Original Solution 1 */
class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (numContainer.count(index) != 0) {
            int prevNum = numContainer[index];
            auto&& ids = valSet[prevNum];
            
            ids.erase(index);
            if (ids.empty()) {
                valSet.erase(prevNum);
            }
        }
        numContainer[index] = number;
        valSet[number].insert(index);
        return;
    }
    
    int find(int number) {
        if (valSet.count(number) == 0) {
            return -1;
        }
        
        return *valSet[number].begin();
    }
    unordered_map<int, int>  numContainer;
    unordered_map<int, set<int>> valSet;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
 
 
 /* Official Solution 1 */
 class NumberContainers {
private:
    unordered_map<int, int> nums;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> heaps;

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        nums[index] = number;
        heaps[number].push(index);
    }

    int find(int number) {
        while (!heaps[number].empty() && nums[heaps[number].top()] != number) {
            heaps[number].pop();
        }
        if (heaps[number].empty()) {
            return -1;
        }
        return heaps[number].top();
    }
};

 /* Official Solution 2 */
class NumberContainers {
private:
    unordered_map<int, int> nums;
    unordered_map<int, set<int>> us;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (nums[index] != 0) {
            us[nums[index]].erase(index);
        }
        us[number].insert(index);
        nums[index] = number;
    }
    
    int find(int number) {
        if (us[number].empty()) {
            return -1;
        }
        return *us[number].begin();
    }
};