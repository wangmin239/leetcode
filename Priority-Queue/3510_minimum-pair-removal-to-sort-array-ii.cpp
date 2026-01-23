/* Official Solution 1 */
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // (相邻元素和，左边那个数的下标)
        int dec = 0; // 递减的相邻对的个数
        for (int i = 0; i + 1 < n; i++) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                dec++;
            }
            pq.emplace(x + y, i);
        }

        // 每个下标的左右最近的未删除下标
        vector<int> left(n + 1), right(n);
        ranges::iota(left, -1);
        ranges::iota(right, 1);

        vector<long long> a(nums.begin(), nums.end());
        int ans = 0;
        while (dec) {
            ans++;

            // 如果堆顶数据与实际数据不符，说明堆顶数据是之前本应删除，但没有删除的数据（懒删除）
            while (right[pq.top().second] >= n || pq.top().first != a[pq.top().second] + a[right[pq.top().second]]) {
                pq.pop();
            }
            auto [s, i] = pq.top();
            pq.pop(); // 删除相邻元素和最小的一对

            // (当前元素，下一个数)
            int nxt = right[i];
            dec -= a[i] > a[nxt]; // 旧数据

            // (前一个数，当前元素)
            int pre = left[i];
            if (pre >= 0) {
                dec -= a[pre] > a[i]; // 旧数据
                dec += a[pre] > s; // 新数据
                pq.emplace(a[pre] + s, pre);
            }

            // (下一个数，下下一个数)
            int nxt2 = right[nxt];
            if (nxt2 < n) {
                dec -= a[nxt] > a[nxt2]; // 旧数据
                dec += s > a[nxt2]; // 新数据（当前元素，下下一个数）
                pq.emplace(s + a[nxt2], i);
            }

            a[i] = s;
            // 删除 nxt
            int l = left[nxt], r = right[nxt];
            right[l] = r; // 模拟双向链表的删除操作
            left[r] = l;
            right[nxt] = n; // 表示删除 nxt
        }

        return ans;
    }
};



/* Official Solution 2 */
typedef long long ll;

const int MAX_N = 100005;

struct Node {
    ll value;
    int left;
};

using ListIt = std::list<Node>::iterator;

struct Pair {
    ListIt first;
    ListIt second;
    ll cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}
    Pair(ListIt fi, ListIt se, ll cost)
        : first(fi), second(se), firstLeft(fi->left), secondLeft(se->left),
          cost(cost) {}
};

struct ComparePair {
    bool operator()(const Pair& a, const Pair& b) {
        if (a.cost != b.cost) {
            return a.cost > b.cost;
        }
        return a.firstLeft > b.firstLeft;
    }
};

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        std::list<Node> list;
        std::bitset<MAX_N> merged;
        std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

        int decreaseCount = 0;
        int count = 0;

        list.push_back({nums[0], 0});

        for (size_t i = 1; i < nums.size(); ++i) {
            list.push_back({nums[i], (int)i});

            auto curr = std::prev(list.end());
            auto prev = std::prev(curr);

            pq.push({prev, curr, prev->value + curr->value});

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (merged[top.firstLeft] || merged[top.secondLeft]) {
                continue;
            }

            auto first = top.first;
            auto second = top.second;
            auto cost = top.cost;

            if (first->value + second->value != cost) {
                continue;
            }

            count++;

            if (first->value > second->value) {
                decreaseCount--;
            }

            ListIt prev =
                (first == list.begin()) ? list.end() : std::prev(first);
            ListIt next = std::next(second);

            if (prev != list.end()) {
                if (prev->value > first->value && prev->value <= cost) {
                    decreaseCount--;
                }
                if (prev->value <= first->value && prev->value > cost) {
                    decreaseCount++;
                }
                pq.push({prev, first, prev->value + cost});
            }

            if (next != list.end()) {
                if (second->value > next->value && cost <= next->value) {
                    decreaseCount--;
                }
                if (second->value <= next->value && cost > next->value) {
                    decreaseCount++;
                }
                pq.push({first, next, cost + next->value});
            }

            first->value = cost;
            merged[second->left] = 1;
            list.erase(second);
        }

        return count;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        set<pair<long long, int>> pairs; // (相邻元素和，左边那个数的下标)
        int dec = 0; // 递减的相邻对的个数
        for (int i = 0; i + 1 < n; i++) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                dec++;
            }
            pairs.emplace(x + y, i);
        }

        set<int> idx; // 剩余下标
        for (int i = 0; i < n; i++) {
            idx.insert(i);
        }

        vector<long long> a(nums.begin(), nums.end());
        int ans = 0;
        while (dec > 0) {
            ans++;

            // 删除相邻元素和最小的一对
            auto [s, i] = *pairs.begin();
            pairs.erase(pairs.begin());

            auto it = idx.lower_bound(i);

            // (当前元素，下一个数)
            auto nxt_it = next(it);
            int nxt = *nxt_it;
            dec -= a[i] > a[nxt]; // 旧数据

            // (前一个数，当前元素)
            if (it != idx.begin()) {
                int pre = *prev(it);
                dec -= a[pre] > a[i]; // 旧数据
                dec += a[pre] > s; // 新数据
                pairs.erase({a[pre] + a[i], pre});
                pairs.emplace(a[pre] + s, pre);
            }

            // (下一个数，下下一个数)
            auto nxt2_it = next(nxt_it);
            if (nxt2_it != idx.end()) {
                int nxt2 = *nxt2_it;
                dec -= a[nxt] > a[nxt2]; // 旧数据
                dec += s > a[nxt2]; // 新数据（当前元素，下下一个数）
                pairs.erase({a[nxt] + a[nxt2], nxt});
                pairs.emplace(s + a[nxt2], i);
            }

            a[i] = s; // 把 a[nxt] 加到 a[i] 中
            idx.erase(nxt); // 删除 nxt
        }
        return ans;
    }
};
