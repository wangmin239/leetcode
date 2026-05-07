/* Official Solution 1 */
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_max(n);
        pre_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i - 1], nums[i]);
        }

        vector<int> ans(n);
        int suf_min = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = pre_max[i] <= suf_min ? pre_max[i] : ans[i + 1];
            suf_min = min(suf_min, nums[i]);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // [value, index]
        using Item = pair<int, int>;
        vector<Item> prevMax(n);

        Item prev = {INT_MIN, -1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > prev.first) {
                prev = {nums[i], i};
            }
            prevMax[i] = prev;
        }

        auto process = [&](auto& self, int r, int rightMin, int rightMax) -> void {
            auto [pMax, pivotIndex] = prevMax[r];
            int currMax = pMax <= rightMin ? pMax : rightMax;

            int nextRightMin = min(pMax, rightMin);
            for (int i = pivotIndex; i <= r; ++i) {
                ans[i] = currMax;
                nextRightMin = min(nextRightMin, nums[i]);
            }

            if (pivotIndex == 0) {
                return;
            }
            
            self(self, pivotIndex - 1, nextRightMin, currMax);
        };

        process(process, n - 1, INT_MAX, 0);

        return ans;
    }
};



/* Official Solution 3 */
class Solution {
public:
    struct Item {
        int value;
        int left;
        int right;
    };

    vector<int> maxValue(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<Item> stack;

        for (int i = 0; i < n; ++i) {
            Item curr = {nums[i], i, i};

            while (!stack.empty() && stack.back().value > nums[i]) {
                Item top = stack.back();
                stack.pop_back();
                curr.value = max(curr.value, top.value);
                curr.left = top.left;
            }

            stack.push_back(curr);
        }

        for (size_t i = 0; i < stack.size(); ++i) {
            for (int j = stack[i].left; j <= stack[i].right; ++j) {
                ans[j] = stack[i].value;
            }
        }

        return ans;
    }
};
