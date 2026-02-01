/* Original Solution 1 */
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());

        return nums[0] + nums[1] + nums[2];
    }
};

/* Original Solution 2 */
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums.front();

        auto minIter = min_element(nums.begin() + 1, nums.end());

        ans += *minIter;

        auto leftMinIter = min_element(nums.begin() + 1, minIter);
        auto rightMinIter = min_element(minIter + 1, nums.end());

        if (leftMinIter == minIter) {
            return ans + *rightMinIter;
        }

        if (rightMinIter == nums.end()) {
            return ans + *leftMinIter;
        }
        return ans + min(*leftMinIter, *rightMinIter);
    }
};

/* Original Solution 3 */
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int minVal = min(nums[1], nums[2]);
        int secondaryMinVal = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {
            if (nums[i] <= minVal) {
                secondaryMinVal = minVal;
                minVal = nums[i];
            } else {
                secondaryMinVal = min(secondaryMinVal, nums[i]);
            }
        }
        
        return nums.front() + minVal + secondaryMinVal;
    }
};