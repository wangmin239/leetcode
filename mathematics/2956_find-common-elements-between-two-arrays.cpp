class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> res(2);
        for (int x : nums1) {
            if (s2.count(x)) {
                res[0]++;
            }
        }
        for (int x : nums2) {
            if (s1.count(x)) {
                res[1]++;
            }
        }
        return res;
    }
};




class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(2);
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    res[0]++;
                    break;
                }
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    res[1]++;
                    break;
                }
            }
        }
        return res;
    }
};





class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unique_ptr<int[]> cnt1, cnt2;
        const int max = 101;
        cnt1 = make_unique_for_overwrite<int[]>(101);
        cnt2 = make_unique_for_overwrite<int[]>(101);
        
        int* ptr1 = cnt1.get();
        int* ptr2 = cnt2.get();
        /* build the map for each number array */
        auto getCnt = [](const vector<int>& nums, int* cnts) {
            for (int num : nums) {
                ++cnts[num];
            }
        };
        /* get the count of the common elements in the two number array */
        auto getCommonCnt = [max](int* cnt1, int* cnt2) {
            int commonCnt = 0;
            for (int i = 0; i < max; i++) {
                if (cnt2[i] != 0) {
                    commonCnt += cnt1[i];
                }
            }
            return commonCnt;               
        };
        
        getCnt(nums1, ptr1);
        getCnt(nums2, ptr2);

        vector<int> ans {0, 0};
        ans[0] = getCommonCnt(ptr1, ptr2);
        ans[1] = getCommonCnt(ptr2, ptr1);
        
        return ans;
    }
};



class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2;
        /* build the map for each number array */
        auto getCnt = [](const vector<int>& nums, unordered_map<int, int>& cnts) {
            for (int num : nums) {
                ++cnts[num];
            }
        };
        /* get the count of the common elements in the two number array */
        auto getCommonCnt = [](const unordered_map<int, int>& cnt1, const
                                unordered_map<int, int>& cnt2) {
            int commonCnt = 0;
            for (auto [num, cnt] : cnt1) {
                if (cnt2.count(num) != 0) {
                    commonCnt += cnt;
                }
            }
            return commonCnt;               
        };
        
        getCnt(nums1, cnt1);
        getCnt(nums2, cnt2);

        vector<int> ans {0, 0};
        ans[0] = getCommonCnt(cnt1, cnt2);
        ans[1] = getCommonCnt(cnt2, cnt1);
        
        return ans;
    }
};