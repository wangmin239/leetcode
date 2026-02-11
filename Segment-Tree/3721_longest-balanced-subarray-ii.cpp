/* Official Solution 1 */
struct LazyTag {
    int to_add = 0;

    LazyTag& operator+=(const LazyTag& other) {
        this->to_add += other.to_add;
        return *this;
    }

    bool has_tag() const { return to_add != 0; }

    void clear() { to_add = 0; }
};

struct SegmentTreeNode {
    int min_value = 0;
    int max_value = 0;
    // int data = 0; // 只有叶子节点使用, 本题不需要
    LazyTag lazy_tag;
};

class SegmentTree {
public:
    int n;
    vector<SegmentTreeNode> tree;

    SegmentTree(const vector<int>& data) : n(data.size()) {
        tree.resize(n * 4 + 1);
        build(data, 1, n, 1);
    }

    void add(int l, int r, int val) {
        LazyTag tag{val};
        update(l, r, tag, 1, n, 1);
    }

    int find_last(int start, int val) {
        if (start > n) {
            return -1;
        }
        return find(start, n, val, 1, n, 1);
    }

private:
    inline void apply_tag(int i, const LazyTag& tag) {
        tree[i].min_value += tag.to_add;
        tree[i].max_value += tag.to_add;
        tree[i].lazy_tag += tag;
    }

    inline void pushdown(int i) {
        if (tree[i].lazy_tag.has_tag()) {
            LazyTag tag = tree[i].lazy_tag;
            apply_tag(i << 1, tag);
            apply_tag(i << 1 | 1, tag);
            tree[i].lazy_tag.clear();
        }
    }

    inline void pushup(int i) {
        tree[i].min_value =
            std::min(tree[i << 1].min_value, tree[i << 1 | 1].min_value);
        tree[i].max_value =
            std::max(tree[i << 1].max_value, tree[i << 1 | 1].max_value);
    }

    void build(const vector<int>& data, int l, int r, int i) {
        if (l == r) {
            tree[i].min_value = tree[i].max_value = data[l - 1];
            return;
        }

        int mid = l + ((r - l) >> 1);
        build(data, l, mid, i << 1);
        build(data, mid + 1, r, i << 1 | 1);

        pushup(i);
    }

    void update(int target_l, int target_r, const LazyTag& tag, int l, int r,
                int i) {
        if (target_l <= l && r <= target_r) {
            apply_tag(i, tag);
            return;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);
        if (target_l <= mid)
            update(target_l, target_r, tag, l, mid, i << 1);
        if (target_r > mid)
            update(target_l, target_r, tag, mid + 1, r, i << 1 | 1);
        pushup(i);
    }

    int find(int target_l, int target_r, int val, int l, int r, int i) {
        if (tree[i].min_value > val || tree[i].max_value < val) {
            return -1;
        }

        // 根据介值定理，此时区间内必然存在解
        if (l == r) {
            return l;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);

        // target_l 一定小于等于 r(=n)
        if (target_r >= mid + 1) {
            int res = find(target_l, target_r, val, mid + 1, r, i << 1 | 1);
            if (res != -1)
                return res;
        }

        if (l <= target_r && mid >= target_l) {
            return find(target_l, target_r, val, l, mid, i << 1);
        }

        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        map<int, queue<int>> occurrences;
        auto sgn = [](int x) { return (x % 2) == 0 ? 1 : -1; };

        int len = 0;
        vector<int> prefix_sum(nums.size(), 0);

        prefix_sum[0] = sgn(nums[0]);
        occurrences[nums[0]].push(1);

        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1];
            auto& occ = occurrences[nums[i]];
            if (occ.empty()) {
                prefix_sum[i] += sgn(nums[i]);
            }
            occ.push(i + 1);
        }

        SegmentTree seg(prefix_sum);

        for (int i = 0; i < nums.size(); i++) {
            len = std::max(len, seg.find_last(i + len, 0) - i);

            auto next_pos = nums.size() + 1;
            occurrences[nums[i]].pop();
            if (!occurrences[nums[i]].empty()) {
                next_pos = occurrences[nums[i]].front();
            }

            seg.add(i + 1, next_pos - 1, -sgn(nums[i]));
        }

        return len;
    }
};


/* Official Solution 2 */
class LazySegmentTree {
    using T = pair<int, int>;
    using F = int;

    // 懒标记初始值
    const F TODO_INIT = 0;

    struct Node {
        T val;
        F todo;
    };

    int n;
    vector<Node> tree;

    // 合并两个 val
    T merge_val(const T& a, const T& b) const {
        return {min(a.first, b.first), max(a.second, b.second)};
    }

    // 合并两个懒标记
    F merge_todo(const F& a, const F& b) const {
        return a + b;
    }

    // 把懒标记作用到 node 子树（本例为区间加）
    void apply(int node, int l, int r, F todo) {
        Node& cur = tree[node];
        // 计算 tree[node] 区间的整体变化
        cur.val.first += todo;
        cur.val.second += todo;
        cur.todo = merge_todo(todo, cur.todo);
    }

    // 把当前节点的懒标记下传给左右儿子
    void spread(int node, int l, int r) {
        Node& cur = tree[node];
        F todo = cur.todo;
        if (todo == TODO_INIT) { // 没有需要下传的信息
            return;
        }
        int m = (l + r) / 2;
        apply(node * 2, l, m, todo);
        apply(node * 2 + 1, m + 1, r, todo);
        cur.todo = TODO_INIT; // 下传完毕
    }

    // 合并左右儿子的 val 到当前节点的 val
    void maintain(int node) {
        tree[node].val = merge_val(tree[node * 2].val, tree[node * 2 + 1].val);
    }

    // 用 a 初始化线段树
    // 时间复杂度 O(n)
    void build(const vector<T>& a, int node, int l, int r) {
        Node& cur = tree[node];
        cur.todo = TODO_INIT;
        if (l == r) { // 叶子
            cur.val = a[l]; // 初始化叶节点的值
            return;
        }
        int m = (l + r) / 2;
        build(a, node * 2, l, m); // 初始化左子树
        build(a, node * 2 + 1, m + 1, r); // 初始化右子树
        maintain(node);
    }

    void update(int node, int l, int r, int ql, int qr, F f) {
        if (ql <= l && r <= qr) { // 当前子树完全在 [ql, qr] 内
            apply(node, l, r, f);
            return;
        }
        spread(node, l, r);
        int m = (l + r) / 2;
        if (ql <= m) { // 更新左子树
            update(node * 2, l, m, ql, qr, f);
        }
        if (qr > m) { // 更新右子树
            update(node * 2 + 1, m + 1, r, ql, qr, f);
        }
        maintain(node);
    }

    // 查询 [ql,qr] 内第一个等于 target 的元素下标
    // 找不到返回 -1
    int find_first(int node, int l, int r, int ql, int qr, int target) {
        // 不相交 或 target 不在当前区间的 [min,max] 范围内
        if (l > qr || r < ql || target < tree[node].val.first || target > tree[node].val.second) {
            return -1;
        }
        if (l == r) {
            // 此处必然等于 target
            return l;
        }
        spread(node, l, r);
        int m = (l + r) / 2;
        int idx = find_first(node * 2, l, m, ql, qr, target);
        if (idx < 0) {
            // 去右子树找
            idx = find_first(node * 2 + 1, m + 1, r, ql, qr, target);
        }
        return idx;
    }

public:
    // 线段树维护一个长为 n 的数组（下标从 0 到 n-1），元素初始值为 init_val
    LazySegmentTree(int n, T init_val = {0, 0}) : LazySegmentTree(vector<T>(n, init_val)) {}

    // 线段树维护数组 a
    LazySegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) {
        build(a, 1, 0, n - 1);
    }

    // 用 f 更新 [ql, qr] 中的每个 a[i]
    // 0 <= ql <= qr <= n-1
    // 时间复杂度 O(log n)
    void update(int ql, int qr, F f) {
        update(1, 0, n - 1, ql, qr, f);
    }

    // 查询 [ql, qr] 内第一个等于 target 的元素下标
    // 找不到返回 -1
    // 0 <= ql <= qr <= n-1
    // 时间复杂度 O(log n)
    int find_first(int ql, int qr, int target) {
        return find_first(1, 0, n - 1, ql, qr, target);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        LazySegmentTree t(n + 1);

        unordered_map<int, int> last; // nums 的元素上一次出现的位置
        int ans = 0, cur_sum = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int v = x % 2 ? 1 : -1;
            auto it = last.find(x);
            if (it == last.end()) { // 首次遇到 x
                cur_sum += v;
                t.update(i, n, v); // sum 的 [i,n] 增加 v
            } else { // 再次遇到 x
                int j = it->second;
                t.update(j, i - 1, -v); // 撤销之前对 sum 的 [j,i-1] 的增加
            }
            last[x] = i;

            // 把 i-1 优化成 i-1-ans，因为在下标 > i-1-ans 中搜索是没有意义的，不会把答案变大
            int j = t.find_first(0, i - 1 - ans, cur_sum);
            if (j >= 0) {
                ans = i - j; // 如果找到了，那么答案肯定会变大
            }
        }
        return ans;
    }
};
