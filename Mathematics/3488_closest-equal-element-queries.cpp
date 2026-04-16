/* Original Solution 1 */
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> numIndexs;

        for (int i = 0; i < n; i++) {
            numIndexs[nums[i]].push_back(i);
        }

        int size = queries.size();
        vector<int> ans(size, -1);
        int i = -1;

        for (const int& key : queries) {
            const auto& ids = numIndexs[nums[key]];
            int len = ids.size();

            ++i;
            if (len == 1) {
                continue;
            }

            int pos = lower_bound(ids.begin(), ids.end(), key) - ids.begin();
            int nextPos = pos + 1;
            int prevPos = pos + len - 1;
            ans[i] = ids[nextPos % len] + n * (nextPos / len) - ids[pos];
            ans[i] = min(ans[i], ids[pos] - ids[prevPos % len] + (1 - prevPos / len) * n);
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> left(n), right(n);
        unordered_map<int, int> pos;
        for (int i = -n; i < n; i++) {
            if (i >= 0) {
                left[i] = pos[nums[i]];
            }
            pos[nums[(i + n) % n]] = i;
        }
        pos.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n) {
                right[i] = pos[nums[i]];
            }
            pos[nums[i % n]] = i;
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int x = queries[i];
            queries[i] = (x - left[x] == n) ? -1 : min(x - left[x], right[x] - x);
        }
        return queries;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> left(n), right(n);
        unordered_map<int, int> first, last; // 记录首次出现和最后一次出现的位置
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            left[i] = last.contains(x) ? last[x] : -1;
            if (left[i] >= 0) {
                right[left[i]] = i;
            }
            if (!first.contains(x)) {
                first[x] = i;
            }
            last[x] = i;
        }

        for (int& i : queries) {
            int l = left[i] >= 0 ? left[i] : last[nums[i]] - n;
            if (i - l == n) {
                i = -1;
            } else {
                int r = right[i] ? right[i] : first[nums[i]] + n;
                i = min(i - l, r - i);
            }
        }
        return queries;
    }
};
