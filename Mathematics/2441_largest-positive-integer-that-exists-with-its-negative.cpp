class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j; j--) {
            while (i < j && nums[i] < -nums[j]) {
                i++;
            }
            if (nums[i] == -nums[j]) {
                return nums[j];
            }
        }
        return -1;
    }
};


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto x : nums) {
            if (s.count(-x)) {
                k = max(k, x);
            }
        }
        return k;
    }
};



class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        for (auto x : nums) {
            auto p = find(nums.begin(), nums.end(), -x);
            if (p != nums.end()) {
                k = max(k, x);
            }
        }
        return k;
    }
};



class Solution {
public:
    int findMaxK(vector<int>& nums) {

        sort(nums.begin(), nums.end(), less<int>());
        auto iter = upper_bound(nums.begin(), nums.end(), 0);
        for (auto left = nums.begin(), right = nums.end() - 1; left < iter; ++left) {
            int value = -*left;
            while (*right > value) {
                --right;
            }
            if (*right == value) {
                return value;
            }
            
            if (right != nums.end() - 1) {
                ++right;
            }
        }       
        return -1;
        
    }
};