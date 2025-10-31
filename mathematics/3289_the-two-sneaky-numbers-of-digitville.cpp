/* Original Solution 1 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

/* Original Solution 2 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int sum = reduce(nums.begin(), nums.end()) - (n - 3) * (n - 2) / 2;
        auto binarySearch = [&nums] (int left, int right) {
                int mid;
                while (left < right) {
                    mid = (left + right) / 2;
                    if (nums[mid] < mid) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                return mid;
        };
        

        sort(nums.begin(), nums.end());
        int mid = binarySearch(0, n);
        
        return {nums[mid], sum - nums[mid]};
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        int xor_all = n ^ (n + 1); // n 和 n+1 多异或了
        for (int i = 0; i < nums.size(); i++) {
            xor_all ^= i ^ nums[i];
        }
        int shift = __builtin_ctz(xor_all);

        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            if (i < n) {
                ans[i >> shift & 1] ^= i;
            }
            ans[nums[i] >> shift & 1] ^= nums[i];
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        int a = -n * (n - 1) / 2;
        int b = -n * (n - 1) * (n * 2 - 1) / 6;
        for (int x : nums) {
            a += x;
            b += x * x;
        }
        int x = (a - (int) sqrt(b * 2 - a * a)) / 2;
        return {x, a - x};
    }
};


/* Official Solution 3 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        int y = 0;
        for (int x : nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int lowBit = y & (-y);
        int x1 = 0, x2 = 0;
        for (int x : nums) {
            if (x & lowBit) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i & lowBit) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return {x1, x2};
    }
};
