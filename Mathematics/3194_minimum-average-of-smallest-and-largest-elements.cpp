class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double res = numeric_limits<double>::max();
        for (int i = 0; i < n / 2; i++) {
            res = min(res, (nums[i] + nums[n - 1 - i]) / 2.0);
        }
        return res;
    }
};


class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int ans;
        size_t size = nums.size();

        sort(nums.begin(), nums.end());
        ans = nums.back() + nums.back();
        
        for (size_t l = 0, r = size - 1; l < r; l++, r--) {
            ans = min(ans, nums[l] + nums[r]);
        }
        
        return static_cast<double>(ans) / 2;
    }
};