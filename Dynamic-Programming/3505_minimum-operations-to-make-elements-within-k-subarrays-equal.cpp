/* Official Solution 1 */
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        priority_queue<int> Left;
        priority_queue<int, vector<int>, greater<int>> Right;
        unordered_map<int, int> delayed;
        int leftSize = 0, rightSize = 0;
        vector<long long> ops(n);
        long long sumL = 0, sumR = 0;

        auto prune = [&](auto& heap) {
            while (!heap.empty()) {
                if (delayed[heap.top()]) {
                    --delayed[heap.top()];
                    heap.pop();
                } else {
                    break;
                }
            }
        };

        auto balance = [&]() {
            if (leftSize > rightSize + 1) {
                int num = Left.top();
                Right.push(num);
                sumR += num;
                sumL -= num;
                Left.pop();
                ++rightSize;
                --leftSize;
                prune(Left);
            } else if (rightSize > leftSize) {
                int num = Right.top();
                Left.push(num);
                sumL += num;
                sumR -= num;
                Right.pop();
                ++leftSize;
                --rightSize;
                prune(Right);
            }
        };

        for (int i = 0; i < n; i++) {
            if (Left.empty() || nums[i] <= Left.top()) {
                Left.push(nums[i]);
                ++leftSize;
                sumL += nums[i];
            } else {
                Right.push(nums[i]);
                ++rightSize;
                sumR += nums[i];
            }
            balance();
            if (i >= x) {
                int num = nums[i - x];
                if (num <= Left.top()) {
                    --leftSize;
                    ++delayed[num];
                    sumL -= num;
                    if (num == Left.top()) {
                        prune(Left);
                    }
                } else {
                    --rightSize;
                    ++delayed[num];
                    sumR -= num;
                    if (num == Right.top()) {
                        prune(Right);
                    }
                }
                balance();
            }

            if (i >= x - 1) {
                long long mid = Left.top();
                ops[i] = sumR - sumL  + mid * (leftSize - rightSize);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MAX));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[x - 1][j] = ops[x - 1];
            } else {
                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
            }
        }
        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i < n; i++) {
                dp[i][j] = min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
            }
        }

        return dp[n - 1][k];
    }
};


/* Official Solution 2 */
class Solution {
    vector<long long> getCosts(const vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> ops(n);

        multiset<int> Left, Right;
        long long sumL = 0, sumR = 0;

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if (Left.empty() || v <= *Left.rbegin()) {
                Left.insert(v);
                sumL += v;
            } else {
                Right.insert(v);
                sumR += v;
            }
            if (i >= x) {   
                v = nums[i - x];
                auto it = Left.find(v);
                if (it != Left.end()) {
                    sumL -= v;
                    Left.erase(it);
                } else {
                    it = Right.find(v);
                    sumR -= v;
                    Right.erase(it);
                }
            }
            if (Left.size() > Right.size() + 1) {
                auto it = prev(Left.end());
                v = *it;
                Right.insert(v);
                Left.erase(it);
                sumL -= v;
                sumR += v;
            } else if (Left.size() < Right.size()) {
                auto it = Right.begin();
                v = *it;
                Left.insert(v);
                Right.erase(it);
                sumL += v;
                sumR -= v;
            }
            if (i >= x - 1) {
                long long mid = *Left.rbegin();
                long long leftCost = mid * (long long)Left.size() - sumL;
                long long rightCost = sumR - mid * (long long)Right.size();
                ops[i] = leftCost + rightCost;
            }
        }
        return ops;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> ops = getCosts(nums, x);
        vector<long long> pre(n + 1, 0);
        vector<long long> cur(n + 1, LLONG_MAX);

        for (int j = 1; j <= k; ++j) {
            fill(cur.begin(), cur.end(), LLONG_MAX);
            for (int i = j * x; i <= n; ++i) {
                cur[i] = min(cur[i - 1], pre[i - x] + ops[i - 1]);
            }
            pre.swap(cur);
        }
        return pre[n];
    }
};


/* Official Solution 3 */
template<typename T, typename Compare = less<T>>
class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt; // 每个元素剩余需要删除的次数
    size_t sz = 0; // 实际大小
    long long s = 0; // 堆中元素总和

    // 正式执行删除操作
    void apply_remove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    long long sum() {
        return s;
    }

    // 删除
    void remove(T x) {
        remove_cnt[x]++; // 懒删除
        sz--;
        s -= x;
    }

    // 查看堆顶
    T top() {
        apply_remove();
        return pq.top();
    }

    // 出堆
    T pop() {
        apply_remove();
        T x = pq.top();
        pq.pop();
        sz--;
        s -= x;
        return x;
    }

    // 入堆
    void push(T x) {
        if (remove_cnt[x] > 0) {
            remove_cnt[x]--; // 抵消之前的删除
        } else {
            pq.push(x);
        }
        sz++;
        s += x;
    }

    // push(x) 然后 pop()
    T push_pop(T x) {
        apply_remove();
        pq.push(x);
        s += x;
        x = pq.top();
        pq.pop();
        s -= x;
        return x;
    }
};

class Solution {
    // 480. 滑动窗口中位数（有改动）
    // 返回 nums 的所有长为 k 的子数组的（到子数组中位数的）距离和
    vector<long long> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        LazyHeap<int> left; // 最大堆
        LazyHeap<int, greater<>> right; // 最小堆

        for (int i = 0; i < n; i++) {
            // 1. 进入窗口
            int in = nums[i];
            if (left.size() == right.size()) {
                left.push(right.push_pop(in));
            } else {
                right.push(left.push_pop(in));
            }

            int l = i + 1 - k;
            if (l < 0) { // 窗口大小不足 k
                continue;
            }

            // 2. 计算答案
            long long v = left.top();
            long long s1 = v * left.size() - left.sum();
            long long s2 = right.sum() - v * right.size();
            ans[l] = s1 + s2;

            // 3. 离开窗口
            int out = nums[l];
            if (out <= left.top()) {
                left.remove(out);
                if (left.size() < right.size()) {
                    left.push(right.pop()); // 平衡两个堆的大小
                }
            } else {
                right.remove(out);
                if (left.size() > right.size() + 1) {
                    right.push(left.pop()); // 平衡两个堆的大小
                }
            }
        }

        return ans;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> dis = medianSlidingWindow(nums, x);
        vector<long long> f(n + 1), g(n + 1); // 滚动数组
        for (int i = 1; i <= k; i++) {
            g[i * x - 1] = LLONG_MAX;
            for (int j = i * x; j <= n - (k - i) * x; j++) {
                g[j] = min(g[j - 1], f[j - x] + dis[j - x]);
            }
            swap(f, g);
        }
        return f[n];
    }
};