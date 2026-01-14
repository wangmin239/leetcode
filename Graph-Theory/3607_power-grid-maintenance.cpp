/* Official Solution 1 */
class Vertex {
public:
    int vertexId;
    bool offline = false;
    int powerGridId = -1;

    Vertex() {}
    Vertex(int id) : vertexId(id) {}
};

using PowerGrid = priority_queue<int, vector<int>, greater<int>>;
using Graph = vector<vector<int>>;

class Solution {
private:
    vector<Vertex> vertices = vector<Vertex>();

    void traverse(Vertex& u, int powerGridId, PowerGrid& powerGrid,
                  Graph& graph) {
        u.powerGridId = powerGridId;
        powerGrid.push(u.vertexId);
        for (int vid : graph[u.vertexId]) {
            Vertex& v = vertices[vid];
            if (v.powerGridId == -1)
                traverse(v, powerGridId, powerGrid, graph);
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        Graph graph(c + 1);
        vertices.resize(c + 1);

        for (int i = 1; i <= c; i++) {
            vertices[i] = Vertex(i);
        }

        for (auto& conn : connections) {
            graph[conn.at(0)].push_back(conn.at(1));
            graph[conn.at(1)].push_back(conn.at(0));
        }

        vector<PowerGrid> powerGrids;

        for (int i = 1, powerGridId = 0; i <= c; i++) {
            auto& v = vertices[i];
            if (v.powerGridId == -1) {
                PowerGrid powerGrid;
                traverse(v, powerGridId, powerGrid, graph);
                powerGrids.push_back(powerGrid);
                powerGridId++;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int op = q.at(0), x = q.at(1);
            if (op == 1) {
                if (!vertices[x].offline) {
                    ans.push_back(x);
                } else {
                    auto& powerGrid = powerGrids[vertices[x].powerGridId];
                    while (!powerGrid.empty() &&
                           vertices[powerGrid.top()].offline) {
                        powerGrid.pop();
                    }
                    ans.push_back(!powerGrid.empty() ? powerGrid.top() : -1);
                }
            } else if (op == 2) {
                vertices[x].offline = true;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class DSU {
public:
    vector<int> parent;
    DSU(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void join(int u, int v) { parent[find(v)] = find(u); }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c + 1);

        for (auto& p : connections) {
            dsu.join(p[0], p[1]);
        }

        vector<bool> online(c + 1, true);
        vector<int> offlineCounts(c + 1, 0);
        unordered_map<int, int> minimumOnlineStations;

        for (auto& q : queries) {
            int op = q[0], x = q[1];
            if (op == 2) {
                online[x] = false;
                offlineCounts[x]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            if (!minimumOnlineStations.count(root)) {
                minimumOnlineStations[root] = -1;
            }

            int station = minimumOnlineStations[root];
            if (online[i]) {
                if (station == -1 || station > i) {
                    minimumOnlineStations[root] = i;
                }
            }
        }

        vector<int> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            int op = queries[i][0], x = queries[i][1];
            int root = dsu.find(x);
            int station = minimumOnlineStations[root];

            if (op == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    ans.push_back(station);
                }
            }

            if (op == 2) {
                if (offlineCounts[x] > 1) {
                    offlineCounts[x]--;
                } else {
                    online[x] = true;
                    if (station == -1 || station > x) {
                        minimumOnlineStations[root] = x;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
