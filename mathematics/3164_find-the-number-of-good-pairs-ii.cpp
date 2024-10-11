class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> count, count2;
        int max1 = 0;
        for (int num : nums1) {
            count[num]++;
            max1 = max(max1, num);
        }
        for (int num : nums2) {
            count2[num]++;
        }
        long long res = 0;
        for (const auto& pair : count2) {
            int a = pair.first, cnt = pair.second;
            for (int b = a * k; b <= max1; b += a * k) {
                if (count.count(b) > 0) {
                    res += 1L * count[b] * cnt;
                }
            }
        }
        return res;

    }
};





class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt = 0;
        map<int, int> nums1Map, nums2Map;
     
        auto initMap1 = [](map<int, int>& unmap, const vector<int>& nums, const int mod) {
            for (int val : nums) {
                if (val % mod == 0) {
                    ++unmap[val / mod];
                }
            }
        };
        auto initMap2 = [](map<int, int>& unmap, const vector<int>& nums) {
            for (int val : nums) {
                ++unmap[val];
            }
        };
        
        initMap1(nums1Map, nums1, k);
        initMap2(nums2Map, nums2);
        
        for (auto& [val2, cnt2] : nums2Map) {
            auto iter = nums1Map.lower_bound(val2);
            while (iter != nums1Map.end()) {
                if (iter->first % val2 == 0) {
                    cnt += static_cast<long long>(cnt2) * iter->second;
                }
                ++iter;
            }
        }

        
        return cnt;
    }
};






class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt = 0;
        map<int, int> nums1Map, nums2Map;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto initMap = [](map<int, int>& unmap, const vector<int>& nums) {
            for (int val : nums) {
                ++unmap[val];
            }
        };
        
        initMap(nums1Map, nums1);
        initMap(nums2Map, nums2);
        
        for (auto& [val2, cnt2] : nums2Map) {
            int mulVal = val2 * k;
            auto iter = nums1Map.lower_bound(mulVal);
            while (iter != nums1Map.end()) {
                if (iter->first % mulVal == 0) {
                    cnt += static_cast<long long>(cnt2) * iter->second;
                }
                ++iter;
            }
        }

        
        return cnt;
    }
};







class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt = 0;
        unordered_map<int, int> nums1Map, nums2Map;
        
        auto initMap = [](unordered_map<int, int>& unmap, const vector<int>& nums) {
            for (int val : nums) {
                ++unmap[val];
            }
        };
        
        initMap(nums1Map, nums1);
        initMap(nums2Map, nums2);
        
        for (auto& [val2, cnt2] : nums2Map) {
            for (auto& [val1, cnt1] : nums1Map) {
                if (val1 % (val2 * k) == 0) {
                    cnt += static_cast<long long>(cnt2) * cnt1;
                }
            }
        }

        
        return cnt;
    }
};





class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt = 0;
        
        sort(nums1.begin(), nums1.end());
        
        for (int val : nums2) {
            int mulVal = val * k;
            size_t pos = lower_bound(nums1.begin(), nums1.end(), mulVal) - nums1.begin();
            
            for (size_t i = pos; i < nums1.size(); i++) {
                if (nums1[i] % mulVal == 0) {
                    ++cnt;
                }
            }
            
        }
        
        return cnt;
    }
};






class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt = 0;
        
        sort(nums1.begin(), nums1.end());
        for (int& val : nums1) {
            val 
        
        for (int val : nums2) {
            size_t pos = lower_bound(nums1.begin(), nums1.end(), mulVal) - nums1.begin();
            
            for (size_t i = pos; i < nums1.size(); i++) {
                if (nums1[i] % val == 0) {
                    ++cnt;
                }
            }
            
        }
        
        return cnt;
    }
};