class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for (int num : nums) {
            if (num > 0) {
                pos++;
            } else if (num < 0) {
                neg++;
            }
        }
        return max(pos, neg);
    }
};

class Solution {
public:
    int lowerBound(vector<int>& nums, int val) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= val) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    int maximumCount(vector<int>& nums) {
        int pos1 = lowerBound(nums, 0);
        int pos2 = lowerBound(nums, 1);
        return max(pos1, (int) nums.size() - pos2);
    }
};





class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int positiveNum = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        int negtiveNum = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        return max(positiveNum, negtiveNum);
        
    }
};


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int positiveNum = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        auto negtiveIter = upper_bound(nums.begin(), nums.end(), -1);
        int negtiveNum = n;
        
        if (negtiveIter != nums.end()) {
            negtiveNum = negtiveIter - nums.begin();
        }
        
        return max(positiveNum, negtiveNum);
        
    }
};



class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int positiveNum = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        auto negtiveNum = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        
        return max(positiveNum, negtiveNum);
        
    }
};