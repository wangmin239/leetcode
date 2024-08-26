/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> mp;
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }

        int total = 0;
        queue<int> que;
        que.push(id);
        while (!que.empty()) {
            int curId = que.front();
            que.pop();
            Employee *employee = mp[curId];
            total += employee->importance;
            for (int subId : employee->subordinates) {
                que.push(subId);
            }
        }
        return total;
    }
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee *> mp;

    int dfs(int id) {
        Employee *employee = mp[id];
        int total = employee->importance;
        for (int subId : employee->subordinates) {
            total += dfs(subId);
        }
        return total;
    }

    int getImportance(vector<Employee *> employees, int id) {
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(id);
    }
};



/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getMaxId(vector<Employee*> employees) {
        int maxId = 0;
        for (const auto& ele : employees) {
            maxId = max(maxId, ele->id);
        }
        
        return maxId;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        constexpr int maxEle = getMaxId(employees) + 1;
        
        unique_ptr<Employee*[]>  uniq(new Employee*[maxEle]);
        
        Employee** pq = uniq.get();
        
        for (const auto ele : employees) {
            pq[ele->id] = ele;
        }
        
        function<int(Employee**, int)> dfs = [&](Employee** pq, int id) {
            Employee* p = pq[id];
            int sum = p->importance;
            
            for (int subId : p->subordinates) {
                sum += dfs(pq, subId);
            }
            
            return sum;
        };
        
        return dfs(pq,  id);
    }
};



/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        for (const auto ele : employees) {
            if (ele->id != id) {
                continue;
            }
            sum = ele->importance;
            for (const int subId: ele->subordinates) {
                sum += getImportance(employees, subId);
            }
            break;
        }
        return sum;
    }
};