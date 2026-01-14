class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ret;
        int n = buildings.size(), idx = 0;
        for (auto& boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!que.empty() && que.top().first <= boundary) {
                que.pop();
            }

            int maxn = que.empty() ? 0 : que.top().second;
            if (ret.size() == 0 || maxn != ret.back()[1]) {
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
        
        for (auto& e : buildings) {
            all.insert(make_pair(e[0], -e[2])); // critical point, left corner
            all.insert(make_pair(e[1], e[2])); // critical point, right corner
        }
        
        multiset<int> heights({0}); // 保存当前位置所有高度。
        vector<int> last = {0, 0}; // 保存上一个位置的横坐标以及高度
        for (auto& p : all) {
            if (p.second < 0) heights.insert(-p.second); // 左端点，高度入堆
            else heights.erase(heights.find(p.second)); // 右端点，移除高度
            
            // 当前关键点，最大高度
            auto maxHeight = *heights.rbegin();
            
            // 当前最大高度如果不同于上一个高度，说明这是一个转折点
            if (last[1] != maxHeight) {
                // 更新 last，并加入结果集
                last[0] = p.first;
                last[1] = maxHeight;
                res.push_back(last);
            }
        }
        
        return res;
    }
};


