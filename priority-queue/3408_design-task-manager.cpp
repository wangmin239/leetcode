/* Original Solution 1 */
class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        needUpdate = false;
     
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskUsers[taskId] = userId;
        edit(taskId, priority);
    }

#define INVALID (-1)    
    void edit(int taskId, int newPriority) {
        updatePr[taskId] = newPriority;
        needUpdate = true;
    }
    
    void rmv(int taskId) {
        edit(taskId, INVALID);
        taskUsers.erase(taskId);
    }
    
    void updatePq() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lessComp)> tmp{lessComp};
        
        while (pq.empty() == false) {
            auto [pr, id] = pq.top();
            pq.pop();
            
            if (updatePr.count(id) == 0) {
                tmp.emplace(pr, id);
            }
        }
        /* filter the caceled task */
        for (auto [id, pr] : updatePr) {
            if (pr != INVALID) {
                tmp.emplace(pr, id);
            }
        }
            
        updatePr.clear();
        pq = move(tmp);
        needUpdate = false;
    }
    
    int execTop() {
        if (needUpdate == true) {
            updatePq();
        }
        int userId = INVALID;
        if (pq.empty() == true) {
            return INVALID;
        }
        

        int taskId = pq.top().second;
        
        pq.pop();
        userId = taskUsers[taskId]; 
        rmv(taskId);

        return userId;
        
    }
    function<bool(pair<int, int>&, pair<int, int>&)> lessComp = [](const auto& lhs, const auto& rhs) {
        return lhs.first == rhs.first ? lhs.second < rhs.second: lhs.first < rhs.first;
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lessComp)> pq{lessComp};
    unordered_map<int, int> updatePr;
    unordered_map<int, int> taskUsers;
    bool needUpdate;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
 
/* Official Solution 1 */ 
class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<int, int>> heap;
    
public:
    TaskManager(vector<vector<int>> tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskInfo[taskId] = {priority, userId};
            heap.emplace(priority, taskId);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {priority, userId};
        heap.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        if (taskInfo.find(taskId) != taskInfo.end()) {
            taskInfo[taskId].first = newPriority;
            heap.emplace(newPriority, taskId);
        }
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId);
    }
    
    int execTop() {
        while (!heap.empty()) {
            auto [priority, taskId] = heap.top();
            heap.pop();
            
            if (taskInfo.find(taskId) != taskInfo.end() && 
                taskInfo[taskId].first == priority) {
                int userId = taskInfo[taskId].second;
                taskInfo.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */