class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> diff(m + 2);
        for (int x : nums) {
            diff[max(x - k, 0)]++;
            diff[min(x + k + 1, m + 1)]--;
        }
        int res = 0, count = 0;
        for (int x : diff) {
            count += x;
            res = max(res, count);
        }
        return res;
    }
};


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> diff(m + 2);
        for (int x : nums) {
            diff[max(x - k, 0)]++;
            diff[min(x + k + 1, m + 1)]--;
        }
        int res = 0, count = 0;
        for (int x : diff) {
            count += x;
            res = max(res, count);
        }
        return res;
    }
};
