/* Official Solution 1 */
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<tuple<int, int, char>> alive;
        for (int i: idx) {
            int curIdx = i, curHp = healths[i];
            char curDir = directions[i];
            while (!alive.empty()) {
                auto [prevIdx, prevHp, prevDir] = alive.back();
                if (prevDir == 'R' && curDir == 'L') {
                    alive.pop_back();
                    if (prevHp > curHp) {
                        curIdx = prevIdx;
                        curHp = prevHp - 1;
                        curDir = prevDir;
                    } else if (prevHp < curHp) {
                        curHp -= 1;
                    } else {
                        curIdx = -1;
                        break;
                    }
                } else {
                    break;
                }
            }
            if (curIdx != -1) {
                alive.emplace_back(curIdx, curHp, curDir);
            }
        }

        sort(alive.begin(), alive.end());
        vector<int> ans;
        for (auto& [id, hp, dir]: alive) {
            ans.push_back(hp);
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        // 创建一个下标数组，对下标数组排序，这样不会打乱输入顺序
        vector<int> idx(n);
        ranges::iota(idx, 0); // idx[i] = i
        ranges::sort(idx, {}, [&](int i) { return positions[i]; });

        stack<int> st;
        for (int i : idx) {
            if (directions[i] == 'R') { // 机器人 i 向右
                st.push(i);
                continue;
            }
            while (!st.empty()) { // 栈顶机器人向右
                int j = st.top();
                if (healths[j] > healths[i]) { // 栈顶机器人的健康度大
                    healths[i] = 0; // 移除机器人 i
                    healths[j]--;
                    break;
                }
                if (healths[j] == healths[i]) { // 健康度一样大，都移除
                    healths[i] = 0;
                    healths[j] = 0;
                    st.pop();
                    break;
                }
                // 机器人 i 的健康度大
                healths[i]--;
                healths[j] = 0; // 移除机器人 j
                st.pop();
            }
        }

        // 返回幸存机器人的健康度
        vector<int> ans;
        for (int h : healths) {
            if (h > 0) {
                ans.push_back(h);
            }
        }
        return ans;
    }
};
