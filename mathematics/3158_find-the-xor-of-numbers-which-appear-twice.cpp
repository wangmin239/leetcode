class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> cnt;
        int res = 0;
        for (int num : nums) {
            if (cnt.find(num) != cnt.end()) {
                res ^= num;
            } else {
                cnt.emplace(num);
            }
        }
        return res;
    }
};



class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        const int maxVal = 51;
        unique_ptr<int[]> uniq = make_unique<int[]>(maxVal);
        int* ptr = uniq.get();
        
        fill(ptr, ptr + maxVal, 0);
        
        for (int i = 0; i < len; i++) {
            ++ptr[nums[i]];
            if (ptr[nums[i]] == 2) {
                ans ^= nums[i];
            }
        }
        return ans;
    }
};





class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                ans ^= nums[i];
            }
        }
        
        return ans;
    }
};