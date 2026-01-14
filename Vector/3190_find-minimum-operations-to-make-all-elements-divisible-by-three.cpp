/* Original Solution 1 */
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        const int mod = 3;
        int arr[mod] = {0, 1, 1};

        for (int num : nums) {
            ops += arr[num % mod];
        }

        return ops;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) {
            return acc + std::min(v % 3, 3 - v % 3);
        });
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) {
            return acc + std::min(v % 3, 3 - v % 3);
        });
    }
};
