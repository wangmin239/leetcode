/* Original Solution 1 */
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        unordered_set<int> issueSet;

        for (const auto& peer : invocations) {
            adj[peer.front()].push_back(peer.back());
        }


        auto dfs =[&](int nodeId, auto&& self) ->void {
            visited[nodeId] = true;
            issueSet.insert(nodeId);

            for (int nextNodeId : adj[nodeId]) {

                if (visited[nextNodeId] == true) {
                    continue;
                }

                self(nextNodeId, self);
            }
        };

        dfs(k, dfs);

        if (issueSet.size() == n) {
            return {};
        }

        vector<int> ans;
        auto isVisitedIssueSet = [&](int nodeId, vector<bool>& hasVisited, auto&& self) -> bool {
            auto isVisited = false;

            hasVisited[nodeId] = true;
            for (int nextNodeId : adj[nodeId]) {
                if (issueSet.count(nextNodeId)) {
                    return true;
                }

                if (hasVisited[nextNodeId] == false) {
                    isVisited |= self(nextNodeId, hasVisited, self);
                }
            }

            return isVisited;
        };

        for (int i = 0; i < n; i++) {
            if (issueSet.count(i)) {
                continue;
            }

            vector<bool> hasVisited(n, false);
            if (isVisitedIssueSet(i, hasVisited, isVisitedIssueSet) == true) {
                vector<int> allSet(n);
                iota(allSet.begin(), allSet.end(), 0);
                return allSet;
            }
            ans.push_back(i);
        }

        return ans;
    }
};


/* Official Solution 1 */
constexpr int MAXN = 100005;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> inDegree(n, 0);

        bitset<MAXN> suspicious;

        for (const auto& inv : invocations) {
            edges[inv[0]].push_back(inv[1]);
            inDegree[inv[1]]++;
        }

        queue<int> q;
        q.push(k);

        suspicious.set(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                inDegree[v]--;

                if (!suspicious.test(v)) {
                    q.push(v);
                    suspicious.set(v);
                }
            }
        }

        bool canRemoveAll = true;
        vector<int> remaining;

        for (int i = 0; i < n; i++) {
            if (suspicious.test(i) && inDegree[i] > 0) {
                canRemoveAll = false;
                break;
            } else if (!suspicious.test(i)) {
                remaining.push_back(i);
            }
        }

        if (!canRemoveAll) {
            vector<int> allNodes(n);
            iota(allNodes.begin(), allNodes.end(), 0);
            return allNodes;
        }

        return remaining;
    }
};
