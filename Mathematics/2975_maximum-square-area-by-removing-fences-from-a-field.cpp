/* Original Solution 1 */
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long maxArea = -1LL;
        const int mod = 1e9 + 7;

        if (m == n) {
            return 1LL * (m - 1) * (m - 1) % mod;
        }

        int maxWidth = min(m - 1, n - 1);
        auto getSegment = [maxWidth](const vector<int>& fences, int upLimit) {
            int size = fences.size();
            unordered_set<int> width;

            if (upLimit - 1 <= maxWidth) {
                width.insert(upLimit - 1);
            }

            for (int i = 0; i < size; i++) {
                width.insert(fences[i] - 1);
                for (int j = i + 1; j < size; j++) {
                    if (fences[j] - fences[i] <= maxWidth) {
                        width.insert(fences[j] - fences[i]);
                    }
                }
                if (upLimit - fences[i] <= maxWidth) {
                    width.insert(upLimit - fences[i]);
                }
            }

            return width;
        }; 

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        auto&& heights = getSegment(hFences, m);
        auto&& widths = getSegment(vFences, n);


        for (const int height : heights) {
            if (widths.count(height) != 0) {
                maxArea = max(maxArea, 1LL * height * height);
            }
        }

        return maxArea % mod;

    }
};



/* Official Solution 1 */
class Solution {
    unordered_set<int> f(vector<int>& a, int mx) {
        a.push_back(1);
        a.push_back(mx);
        ranges::sort(a);

        // 计算 a 中任意两个数的差，保存到哈希集合中
        unordered_set<int> st;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                st.insert(a[j] - a[i]);
            }
        }
        return st;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        constexpr int MOD = 1'000'000'007;
        unordered_set<int> h_set = f(hFences, m);
        unordered_set<int> v_set = f(vFences, n);

        int ans = 0;
        for (int x : h_set) {
            if (v_set.contains(x)) {
                ans = max(ans, x);
            }
        }
        return ans ? 1LL * ans * ans % MOD : -1;
    }
};



/* Official Solution 2 */
class Solution {
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto e : hEdges) {
            if (vEdges.contains(e)) {
                res = max(res, e);
            }
        }
        if (res == 0) {
            res = -1;
        } else {
            res = 1ll * res * res % 1000000007;
        }
        return res;
    }
};
