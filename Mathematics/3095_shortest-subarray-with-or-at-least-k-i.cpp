
/* First method, brute - force solution */
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size();

        for (int step = 1; step <= size; step++) {
            for (int i = 0; i <= size -step; i++) {
                int value = 0;
                for (int j = 0; j < step; j++) {
                    value |= nums[i + j];
                }

                if (value >= k) {
                    return step;
                }
            }
        }
        return -1;
    }
};

/* Second method, sliping window */
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
        
        auto update = [&bitCnt] (const int val, Opt op) {
            bitset<limit> val2bit(val);
            for (int i = 0; i < limit; i++) {
                if (val2bit[i] == 1) {
                    if (op == ADD) {
                        ++bitCnt[i];
                    } else {
                        --bitCnt[i];
                    }
                }
            }
        };
        
        auto check = [](const int k, int bitCnt[limit]) {
            bitset<limit> bit2Val;


