class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
       int minId, maxId;
       int n = nums.size();

       for (int i = 0; i < n; i++) {
           if (nums[i] == 1) {
               minId = i;
           }
           
           if (nums[i] == n) {
               maxId = i;
           }
       }
       
       int minSteps = minId + n - maxId - 1;
       
       minSteps -= static_cast<int>(minId > maxId);
       return minSteps;
    }
};

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        auto [first, last] = minmax_element(nums.begin(), nums.end());
        return first + nums.size() - 1 - last - (last < first);
    }
};

