/* Official Solution 1 */
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // 记录每个字符的第一次和最后一次出现位置
        unordered_map<char, pair<int, int>> pos;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (pos.find(ch) == pos.end()) {
                pos[ch] = {i, i};
            } else {
                pos[ch].second = i;
            }
        }
        
        // 所有合法的区间
        vector<pair<int, int>> valid;
        
        for (auto& [c, range] : pos) {
            int l = range.first, r = range.second;
            int nl = l, nr = l;
            
            while (nl >= l || nr <= r) {
                int i = (nl >= l) ? nl : nr;
                
                // 当前处理的是字符 s[i]
                int l_t = pos[s[i]].first;
                int r_t = pos[s[i]].second;
                
                // 当前区间左侧还有该字符，需要向左扩展
                if (l_t < l) {
                    l = l_t;
                }
                
                // 当前区间右侧还有该字符，需要向右扩展
                if (r_t > r) {
                    r = r_t;
                }
                
                // 当前处理的是左指针
                if (i == nl) {
                    nl--;
                }
                
                // 当前处理的是右指针
                if (i == nr) {
                    nr++;
                }
            }
            
            valid.push_back({l, r});
        }
        
        // 按右端点升序排序
        sort(valid.begin(), valid.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        
        // 贪心选择互不重叠的区间
        vector<string> ans;
        int end = -1;
        
        for (auto& [left, right] : valid) {
            if (left > end) {
                ans.push_back(s.substr(left, right - left + 1));
                end = right;
            }
        }
        
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // 记录每种字母的出现位置
        vector<int> pos[26];
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        // 构建有向图
        vector<int> g[26];
        for (int i = 0; i < 26; i++) {
            if (pos[i].empty()) {
                continue;
            }
            int l = pos[i][0], r = pos[i].back();
            for (int j = 0; j < 26; j++) {
                if (j == i) {
                    continue;
                }
                auto& q = pos[j];
                int k = ranges::lower_bound(q, l) - q.begin();
                // [l, r] 包含第 j 个小写字母
                if (k < q.size() && q[k] <= r) {
                    g[i].push_back(j);
                }
            }
        }

        // 遍历有向图
        bool vis[26];
        int l, r;
        auto dfs = [&](this auto&& dfs, int x) -> void {
            vis[x] = true;
            l = min(l, pos[x][0]); // 合并区间
            r = max(r, pos[x].back());
            for (int y : g[x]) {
                if (!vis[y]) {
                    dfs(y);
                }
            }
        };

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (pos[i].empty()) {
                continue;
            }
            // 如果要包含第 i 个小写字母，最终得到的区间是什么？
            ranges::fill(vis, false);
            l = INT_MAX;
            r = 0;
            dfs(i);
            intervals.emplace_back(l, r);
        }

        // 435. 无重叠区间
        // 直接计算所选子串
        vector<string> ans;
        ranges::sort(intervals, {}, &pair<int, int>::second);
        int pre_r = -1;
        for (auto& [l, r] : intervals) {
            if (l > pre_r) {
                ans.push_back(s.substr(l, r - l + 1));
                pre_r = r;
            }
        }
        return ans;
    }
};
