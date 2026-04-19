/* Original Solution 1 */
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int distance = 0;

        for (int i = 0, j = 0; i < n1; i++) {
            while (j < n2 && nums1[i] <= nums2[j]) {
                distance = max(distance, j - i);
                j++;
            }
        }

        return distance;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int res = 0;
        for (int j = 0; j < n2; ++j){
            while (i < n1 && nums1[i] > nums2[j]){
                ++i;
            }
            if (i < n1){
                res = max(res, j - i);
            }
        }
        return res;
    }
};
