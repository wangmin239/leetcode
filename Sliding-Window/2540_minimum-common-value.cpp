/* Original Solution 1 */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        for (int i = 0, j = 0; i < len1 && j < len2; ) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }

            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }

        return -1;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            auto it = lower_bound(nums2.begin(), nums2.end(), num);
            if (it != nums2.end() && num == *it) {
                return num;
            }
        }
        return -1;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int num : nums1) {
            mp[num]++;
        }
        for (int num : nums2) {
            if (mp[num]) {
                return num;
            }
        }
        return -1;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};
