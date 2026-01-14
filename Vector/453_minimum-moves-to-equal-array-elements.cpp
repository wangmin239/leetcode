class Solution {
public:
    int minMoves(vector<int>& nums) {
        int steps = 0;
        sort(nums.begin(), nums.end());
        
        if (nums.front() == nums.back()) {
            return 0;
        }
        
        int diff = nums.back() - nums.front();
        for (int i = 0; i < nums.size() - 1; i++) {
            nums[i] += diff;
        }
        return  diff + minMoves(nums);
    }
};



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int steps = 0;
        int minVal;
        

        minVal = *min_element(nums.begin(), nums.end());
        
        auto calcSteps = [&] (auto value) {
            steps += value - minVal;
        };
        
        for_each(nums.begin(), nums.end(), calcSteps);
        return steps;
    }
};


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int steps = 0;
        int minVal;
        

        minVal = *min_element(nums.begin(), nums.end());
        for (const int value : nums) {
            steps += value - minVal;
        }
        return steps;
    }
};