/* Original solution 1 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;

        sort(nums.begin(), nums.end());

        if (nums[0] == nums[n - 1]) {
            return nums[0];
        }
        return nums[n];

    }
};



/* Original solution 2 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }

        return 0;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        mt19937 gen{random_device{}()};
        uniform_int_distribution<int> dis(0, n - 1);

        while (true) {
            int x = dis(gen), y = dis(gen);
            if (x != y && nums[x] == nums[y]) {
                return nums[x];
            }
        }
    }
};


/* Official Solution 2 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int gap = 1; gap <= 3; ++gap) {
            for (int i = 0; i + gap < n; ++i) {
                if (nums[i] == nums[i + gap]) {
                    return nums[i];
                }
            }
        }
        // 不可能的情况
        return -1;
    }
};
