/* Original Solution 1, 425/523 testcases passed */
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int, priority_queue<int, vector<int>, greater<int>> > freq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int key = nums[i];

            freq[key].push(i);
        }

        for (auto& [key, pq] : freq) {
            for (int i = key + 1; i <= key + limit; i++) {
                if (freq.count(i) == 0) {
                    continue;
                }
                priority_queue<int, vector<int>, greater<int>> tmp;
                auto& bigPq = freq[i];

                while (pq.empty() == false ) {
                    int id = pq.top();
                    pq.pop();

                    int swapId = bigPq.top();
                    bigPq.pop();

                    if (id > swapId) {
                        tmp.push(swapId);
                        bigPq.push(id);
                    } else {
                        tmp.push(id);
                        bigPq.push(swapId);
                    }
                }

                while (tmp.empty() == false) {
                    pq.push(tmp.top());
                    tmp.pop();
                }

            }
        }

        for (auto& [key, pq] : freq) {
            while (pq.empty() == false) {
                nums[pq.top()] = key;
                pq.pop();
            }
        }

        return nums;
    }
};



/* Official Solution 1 */
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // 将元素值与原下标绑定
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // 按元素值升序排序
        sort(arr.begin(), arr.end());

        vector<int> values, indices;
        for (auto& p : arr) {
            values.push_back(p.first);
            indices.push_back(p.second);
        }

        int i = 0;
        while (i < n) {
            int start = i;

            // 当前连通块中的原下标
            vector<int> groupIndices;

            // 当前连通块中的元素值
            vector<int> groupValues;

            while (i < n && (i == start || values[i] - values[i - 1] <= limit)) {
                groupIndices.push_back(indices[i]);
                groupValues.push_back(values[i]);
                i++;
            }

            // 由于元素值数组已经有序，这里不需要再排序
            sort(groupIndices.begin(), groupIndices.end());

            // 为得到字典序最小的结果，将较小元素放到较小下标处
            for (int k = 0; k < groupIndices.size(); k++) {
                ans[groupIndices[k]] = groupValues[k];
            }
        }

        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> pos(n);
        ranges::iota(pos, 0); // 初始化 pos[i] = i
        ranges::sort(pos, {}, [&](int i) { return nums[i]; });
        // 排序后，nums[pos[i]] 是递增的

        vector<int> groups;
        vector<int> belong(n);
        for (int i = 0; i < n; i++) {
            int p = pos[i];
            if (i == 0 || nums[p] - nums[pos[i - 1]] > limit) {
                groups.push_back(i); // 新的段，只需记录开始下标
            }
            // 记录 pos[i] 属于哪一段
            belong[p] = groups.size() - 1;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int& cur_idx = groups[belong[i]];
            ans[i] = nums[pos[cur_idx]];
            cur_idx++;
        }
        return ans;
    }
};
