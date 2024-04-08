class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> cnt(nums.begin(), nums.end());
        vector<int> sortedUniqueNums(cnt.begin(), cnt.end());
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        int res = n, j = 0;
        for (int i = 0; i < sortedUniqueNums.size(); i++) {
            int right = sortedUniqueNums[i] + n - 1;
            while (j < sortedUniqueNums.size() && sortedUniqueNums[j] <= right) {
                res = min(res, n - (j - i + 1));
                j++;
            }
        }            
        return res;
    }
};

