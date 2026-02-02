/* Original Solution 1 */

// 两个 multiset 维护前 k 小值
class Container {
public:
    Container(int k): k(k), sm(0) {}

    // 调整有序集合的大小，保证调整后前 k 个最小值均在 st1 
    void adjust() {
        while (st1.size() < k && st2.size() > 0) {
            int x = *(st2.begin());
            st1.emplace(x);
            sm += x;
            st2.erase(st2.begin());
        }
        while (st1.size() > k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            sm -= x;
        }
    }

    // 插入元素 x
    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            sm += x;
        }
        adjust();
    }

    // 删除元素 x
    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it), sm -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    // 前 k 小元素的和
    long long sum() {
        return sm;
    }

private:
    int k;
    // st1 保存前 k 小值，st2 保存其它值
    multiset<int> st1, st2;
    // sm 表示前 k 小元素的和
    long long sm;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // 滑动窗口初始化
        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.sum() + nums[k - 1];
        // 枚举最后一个数组的开头
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
};



/* Original Solution 2 */
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        k--;
        long long sum = reduce(nums.begin(), nums.begin() + dist + 2, 0LL);
        multiset<int> L(nums.begin() + 1, nums.begin() + dist + 2), R;
        auto L2R = [&]() {
            int x = *L.rbegin();
            sum -= x;
            L.erase(L.find(x));
            R.insert(x);
        };
        auto R2L = [&]() {
            int x = *R.begin();
            sum += x;
            R.erase(R.find(x));
            L.insert(x);
        };
        while (L.size() > k) {
            L2R();
        }

        long long ans = sum;
        for (int i = dist + 2; i < nums.size(); i++) {
            // 移除 out
            int out = nums[i - dist - 1];
            auto it = L.find(out);
            if (it != L.end()) {
                sum -= out;
                L.erase(it);
            } else {
                R.erase(R.find(out));
            }

            // 添加 in
            int in = nums[i];
            if (in < *L.rbegin()) {
                sum += in;
                L.insert(in);
            } else {
                R.insert(in);
            }

            // 维护大小
            if (L.size() == k - 1) {
                R2L();
            } else if (L.size() == k + 1) {
                L2R();
            }

            ans = min(ans, sum);
        }
        return ans;
    }
};
