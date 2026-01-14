/* Original Solution */
class Solution {
public:
    string triangleType(vector<int>& nums) {
        /* check if the sum of any two edges is longer than the third edges */
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1]
            || nums[1] + nums[2] <= nums[0]) {
            return "none";
        }
        
        /* The length of the three edges is the same */
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        /* two edges' length is the same */
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }
        
        return "scalene";
        
    }
};

/* Official Solution */
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        } else if (nums[0] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
