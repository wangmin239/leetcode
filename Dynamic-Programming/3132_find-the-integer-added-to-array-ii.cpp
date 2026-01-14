class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i: {2, 1, 0}) {
            int left = i + 1, right = 1;
            while (left < m && right < n) {
                if (nums1[left] - nums2[right] == nums1[i] - nums2[0]) {
                    ++right;
                }
                ++left;
            }
            if (right == n) {
                return nums2[0] - nums1[i];
            }
        }
        // 本题不会有无解的情况
        return 0;
    }
};




class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        const int n = 3;
        int minVal = INT_MAX;
        int size2 = nums2.size();
        int size1 = nums1.size();

        for (int i = 0; i < n; i++) {
            int x = nums2.front() - nums1[i];
            bool isEqual = true;
            int j, left;
            for (j = 0, left = i; j < size2 && left < size1; j++, left++) {
                if (x + nums1[left] > nums2[j]) {
                    isEqual = false;
                    break;
                } else if (x + nums1[left] < nums2[j]) {
                    --j;
                }
            }
            
            /* compare every elements of the array nums2 */
            if (isEqual == true && j == size2) {
                minVal = min(minVal, x);
            }
        }
        
        return minVal;
    }
};

