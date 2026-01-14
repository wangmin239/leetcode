class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (auto v : roads) {
            connect[v[0]][v[1]] = true;
            connect[v[1]][v[0]] = true;
            degree[v[0]]++;
            degree[v[1]]++;
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        vector<int> degree(n);
        for (auto road : roads) {
            int x = road[0], y = road[1];
            connect[x][y] = true;
            connect[y][x] = true;
            degree[x]++;
            degree[y]++;
        }

        int first = -1, second = -2;
        vector<int> firstArr, secondArr;
        for (int i = 0; i < n; ++i) {
            if (degree[i] > first) {
                second = first;
                secondArr = firstArr;
                first = degree[i];
                firstArr.clear();
                firstArr.emplace_back(i);
            } else if (degree[i] == first) {
                firstArr.emplace_back(i);
            } else if (degree[i] > second){
                secondArr.clear();
                second = degree[i];
                secondArr.emplace_back(i);
            } else if (degree[i] == second) {
                secondArr.emplace_back(i);
            }
        }
        if (firstArr.size() == 1) {
            int u = firstArr[0];
            for (int v : secondArr) {
                if (!connect[u][v]) {
                    return first + second;
                }
            }
            return first + second - 1;
        } else {
            int m = roads.size();
            if (firstArr.size() * (firstArr.size() - 1) / 2 > m) {
                return first * 2;
            }
            for (int u: firstArr) {
                for (int v: firstArr) {
                    if (u != v && !connect[u][v]) {
                        return first * 2;
                    }
                }
            }
            return first * 2 - 1;
        }
    }
};
