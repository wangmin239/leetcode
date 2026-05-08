/* Official Solution 1 */
const int MX = 1000001;
vector<int> factors[MX];
bool initialized = []() {
    for (int i = 2; i < MX; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            if (factors[a].size() == 1) {
                edges[a].push_back(i);
            }
        }
        int res = 0;
        vector<bool> seen(n, false);
        seen[n - 1] = true;
        vector<int> q = {n - 1};
        while (true) {
            vector<int> q2;
            for (int i : q) {
                if (i == 0) return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.push_back(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.push_back(i + 1);
                }
                for (int p : factors[nums[i]]) {
                    if (edges.count(p)) {
                        for (int j : edges[p]) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q = move(q2);
            res++;
        }
    }
};

/* Official Solution 2 */
const int MX = 1'000'001;
vector<int> prime_factors[MX];

int init = [] {
    // 预处理每个数的质因子列表，思路同埃氏筛
    for (int i = 2; i < MX; i++) {
        if (prime_factors[i].empty()) { // i 是质数
            for (int j = i; j < MX; j += i) { // i 的倍数有质因子 i
                prime_factors[j].push_back(i);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (prime_factors[x].size() == 1) { // x 是质数
                groups[x].push_back(i);
            }
        }

        int ans = 0;
        vector<int8_t> vis(n);
        vis[n - 1] = true;
        vector<int> q = {n - 1};

        while (true) {
            auto tmp = q;
            q.clear();
            for (int i : tmp) {
                if (i == 0) {
                    return ans;
                }
                if (!vis[i - 1]) {
                    vis[i - 1] = true;
                    q.push_back(i - 1);
                }
                if (i < n - 1 && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.push_back(i + 1);
                }
                // 逆向思维：从 i 倒着跳到 nums[i] 的质因子 p 的下标 j
                for (int p : prime_factors[nums[i]]) {
                    auto it = groups.find(p);
                    if (it != groups.end()) {
                        for (int j : it->second) {
                            if (!vis[j]) {
                                vis[j] = true;
                                q.push_back(j);
                            }
                        }
                        groups.erase(it); // 避免重复访问下标列表
                    }
                }
            }
            ans++;
        }
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-jumps-to-reach-end-via-prime-teleportation/solutions/3734792/bfspythonjavacgo-by-endlesscheng-bu60/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。