class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        bool isExist = false;
        
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len && j <= i + k; j++) {
                if (nums[i] == nums[j]) {
                    isExist = true;
                    break;
                }
            }
        }
        
        return isExist;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dictionary;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            if (dictionary.count(num) && i - dictionary[num] <= k) {
                return true;
            }
            dictionary[num] = i;
        }
        return false;
    }
};




class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dupMap;
        bool isExist = false;

        for (int i = 0; i < nums.size(); i++) {
            if (dupMap.count(nums[i])) {
                if (i - dupMap[nums[i]] <= k) {
                    isExist = true;
                    break;
                }
            }
            dupMap[nums[i]] = i;
        }
        
        return isExist;
                    
    }
};