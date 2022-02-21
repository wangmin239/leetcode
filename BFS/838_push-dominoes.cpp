class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, - 1);
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                q.emplace(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }

        string res(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                res[i] = f;
                int ni = (f == 'L') ? (i - 1) : (i + 1);
                if (ni >= 0 and ni < n) {
                    int t = time[i];
                    if (time[ni] == -1) {
                        q.emplace(ni);
                        time[ni] = t + 1;
                        force[ni].push_back(f);
                    } else if(time[ni] == t + 1) {
                        force[ni].push_back(f);
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0;
        char left = 'L';
        while (i < n) {
            int j = i;
            while (j < n && dominoes[j] == '.') { // 找到一段连续的没有被推动的骨牌
                j++;
            }
            char right = j < n ? dominoes[j] : 'R';
            if (left == right) { // 方向相同，那么这些竖立骨牌也会倒向同一方向
                while (i < j) {
                    dominoes[i++] = right;
                }
            } else if (left == 'R' && right == 'L') { // 方向相对，那么就从两侧向中间倒
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};

