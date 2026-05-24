/* Official Solution 1 */
class Solution {
private:
    vector<int> f;
    
public:
    void dfs(vector<int>& arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        f.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            dfs(arr, i, d, n);
        }
        return *max_element(f.begin(), f.end());
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            int& res = memo[i]; // 注意这里是引用
            if (res) { // 之前计算过
                return res;
            }

            res = 1;

            // 往左跳
            for (int j = i - 1; j >= max(i - d, 0) && arr[j] < arr[i]; j--) {
                res = max(res, dfs(j) + 1);
            }

            // 往右跳
            for (int j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; j++) {
                res = max(res, dfs(j) + 1);
            }

            return res;
        };

        // 枚举起点
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        // 计算 arr[i] 左边最近的更大元素 arr[left[i]]
        vector<int> left(n);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            while (!st.empty() && arr[st.back()] <= x) {
                st.pop_back();
            }
            // 如果左边没有更大的数，或者跳跃距离超过 d，都标记为 -1
            left[i] = st.empty() || i - st.back() > d ? -1 : st.back();
            st.push_back(i);
        }

        // 计算 arr[i] 右边最近的更大元素 arr[right[i]]
        vector<int> right(n);
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            int x = arr[i];
            while (!st.empty() && arr[st.back()] <= x) {
                st.pop_back();
            }
            // 如果右边没有更大的数，或者跳跃距离超过 d，都标记为 -1
            right[i] = st.empty() || st.back() - i > d ? -1 : st.back();
            st.push_back(i);
        }

        vector<int> memo(n);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 0) { // 没有更大的数，或者跳跃距离超过 d
                return 0;
            }
            int& res = memo[i];
            if (res == 0) { // 没有计算过
                // 往左跳 vs 往右跳
                res = max(dfs(left[i]), dfs(right[i])) + 1;
            }
            return res;
        };

        // 枚举终点，倒着跳
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
