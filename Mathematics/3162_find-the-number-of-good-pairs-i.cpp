class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt = 0;
        
        for (int val2 : nums2) {
            for (int val1 : nums1) {
                if (val1 % (val2 * k) == 0) {
                    ++cnt;
                }
            }
        }
  
        return cnt;
    }
};




class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        
        for (auto val : nums2) {
            int curVal = val * k;
            size_t pos = lower_bound(nums1.begin(), nums1.end(), curVal) - nums1.begin();
            while (pos < nums1.size()) {
                if (nums1[pos++] % curVal == 0) {
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
};