class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int cnt = 0;

       for (int val : nums) {
           cnt += static_cast<int>(val < k);
       }
       
       return cnt;
    }
};



class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

       auto iter = lower_bound(nums.begin(), nums.end(), k);
       
       return iter - nums.begin();
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for (int num: nums) {
            if (num < k) {
                res++;
            }
        }
        return res;
    }
};
