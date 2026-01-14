/* Original Solution 1 */
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        vector<int> ans(n);
        vector<int> suffix(n);

        
        suffix[n - 1] = nums[n - 1];
        /* Get the maximum value of the whole array */
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i] | suffix[i + 1];
        }


        int curVal = 0;
        int subArray[32] = {0};
        
        for (int left = 0, right = 0; left < n; left++) {
            const int suffixMax = suffix[left];
            
            while (curVal != suffixMax) {
                curVal |= nums[right];
                
                bitset<32> curSet(nums[right]);
                for (int i = 0; i < 32; i++) {
                    subArray[i] += curSet[i];
                }
                ++right;
            }
            
            ans[left] = right > left? right - left : 1;
            
            bitset<32> preVal(nums[left]);
            for (int i = 0; i < 32; i++) {
                if (preVal[i] == 1 && subArray[i] == 1) {
                    curVal ^= static_cast<int>(0x1 << i);
                }
                subArray[i] -= preVal[i];
            }
        }
        
        return ans;
    }
};

/* Original Solution 2 */
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        vector<int> ans(n);
        vector<int> suffix(n);
        
        suffix[n - 1] = nums[n - 1];
        /* Get the maximum value of the whole array */
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i] | suffix[i + 1];
        }
        
        unordered_map<int, int> subArray;
        int left = 0;
        
        for (int left = 0; left < n; left++) {
            int curVal = 0;
            for (int i = left; i < n; i++) {
                curVal |= nums[i];
                if (curVal == suffix[left]) {
                    ans[left] = i - left + 1;
                    break;
                }
            }
        }
        
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(31, -1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) {
                if (!(nums[i] & (1 << bit))) {
                    if (pos[bit] != -1) {
                        j = max(j, pos[bit]);
                    }
                }
                else {
                    pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
};
