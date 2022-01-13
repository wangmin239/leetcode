class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m1 = -1, m2 = -1;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                index = i;
            } else if (nums[i] > m2) {
                m2 = nums[i];
            }
        }
        return m1 >= m2 * 2 ? index : -1;
    }
};



class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = INT_MIN;
        int secondMax = INT_MIN;
        int index;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;
                maxVal = nums[i];
                index = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        
        if ((maxVal >> 1) >= secondMax) {
            return index;
        }
        
        return -1;
    }
};