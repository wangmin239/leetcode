/* Original Solution 1 */
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int group = 1;
        
        sort(nums.begin(), nums.end());
        
        int minVal = nums.front();
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] - minVal > k) {
                ++group;
                minVal = nums[i];
            }    
        }
        return group;
    }
};