/* Original Solution 1 */
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> digits(nums.begin(), nums.end());
        
        while (digits.count(original) != 0) {
            original *= 2;
        }
        
        return original;
    }
};

/* Original Solution 2 */
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        
        while (binary_search(nums.begin(), nums.end(), original) == true) {
            original *= 2;
        }
        
        return original;
    }
};



/* Original Solution 3 */
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        auto findIter = [&nums](int start, const int value) {
          auto iter = lower_bound(nums.begin() + start, nums.end(), value);
          
          if (iter != nums.end() && *iter == value) {
              return iter - nums.begin();
          }
          return nums.end() - nums.begin();
              
        };
        
        size_t index = findIter(0, original);
        while (index != nums.end() - nums.begin()) {
            original <<= 1;
            index = findIter(index + 1, original);
        }
        
        return original;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int mask = 0;
        for (int x : nums) {
            int k = x / original;
            if (x % original == 0 && (k & (k - 1)) == 0) {
                mask |= k;
            }
        }

        // 找最低的 0，等价于取反后，找最低的 1（lowbit）
        mask = ~mask;
        return original * (mask & -mask);
    }
};
