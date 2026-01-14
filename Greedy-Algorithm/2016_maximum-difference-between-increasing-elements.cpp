/* Official Solution 1 */
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};



/* Original Solution 1 */
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        auto dfs = [&nums](size_t left, size_t right, auto&& innerDfs) {
            if (right <= left + 1) {
                return -1;
            }
            auto begin = nums.begin();
            auto maxIter = max_element(begin + left, begin + right);
            auto minIter = min_element(begin + left, begin + right);
            
            if (minIter <= maxIter) {
                int diff = *maxIter - *minIter;
                return diff <= 0 ? -1 : diff;
            }
            
            int front = innerDfs(left, maxIter - begin + 1, innerDfs);
            int mid = innerDfs(maxIter - begin + 1, minIter - begin, innerDfs);
            int back = innerDfs(minIter - begin,  right, innerDfs);
            
            return max(max(front, mid), back);
        };
        
        ans = dfs(0, nums.size(), dfs);
        
        return ans;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int size = nums.size();
        
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[j] > nums[i]) {
                    ans = max(ans, nums[j] - nums[i]);
                }
            }
        }
        
        return ans;
    }
};