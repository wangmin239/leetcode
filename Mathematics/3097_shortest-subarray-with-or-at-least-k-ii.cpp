
/* Original method, sliping window */
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size();
        int sum = 0;
        int step = INT_MAX;
        const int limit = 32;
        int bitCnt[limit] = {0};
        typedef enum tagOp {
            ADD = 1,
            DEL = 2,
        } Opt;
        
        auto update = [&bitCnt] (int val, Opt op) {
            for (int i = 0; val != 0; i++) {
                if (op == ADD) {
                    bitCnt[i] += val & 0x1;
                } else {
                   bitCnt[i] -= val & 0x1;
                }
                val >>= 1;
            }
        };
        
        auto check = [](const int k, int bitCnt[limit]) {
            int bit2Val = 0;
            for (int i = 0; i < limit; i++) {
                if (bitCnt[i] != 0) {
                    bit2Val += 0x1 << i;
                }
            }
            return bit2Val >= k;
        };
        
        for (int left = 0, right = 0; right < size; right++) {
            if (nums[right] >= k) {
                return 1;
            }

            update(nums[right], ADD);
            while (check(k, bitCnt) == true) {
                step = min(step, right - left + 1);
                update(nums[left], DEL);
                ++left;
            }
        }
        return step != INT_MAX ? step : -1;
    }

};

/* Official method, sliping window */
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(30);
        auto calc = [](vector<int> &bits) -> int {
            int ans = 0;
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] > 0) {
                    ans |= 1 << i;
                }
            }
            return ans;
        };

        int res = INT_MAX;
        for (int left = 0, right = 0; right < n; right++) {
            for (int i = 0; i < 30; i++) {
                bits[i] += (nums[right] >> i) & 1;
            }
            while (left <= right && calc(bits) >= k) {
                res = min(res, right - left + 1);
                for (int i = 0; i < 30; i++) {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left++;
            }
        }
        
        return res == INT_MAX ? -1: res;
    }
};
