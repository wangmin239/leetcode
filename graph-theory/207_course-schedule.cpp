class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};




class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>  graphy(numCourses, vector<int>());
        
        for (const auto& vec : prerequisites) {
            graphy[vec.front()].push_back(vec.back());
        }
        
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            queue<int>  courseQue;
            courseQue.push(i);
            unordered_set<int> learned;
            learned.insert(i);
 
            while (courseQue.empty() != true) {
                int size = courseQue.size();
                while (size-- != 0) {
                    int course = courseQue.front();
                    courseQue.pop();
                    for (int next : graphy[course]) {
                        if (learned.count(next) > 0) {
                            return false;
                        }
                        learned.insert(next);
                        courseQue.push(next);
                        visited[next] = 1;
                    }
                }
                
            }
            visited[i] = 1;
        }
        
        return accumulate(visited.begin(), visited.end(), 0) == numCourses;
    }
};