/* Original Solution 1 */
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        int upLimit = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> freq(upLimit, 0);

        for (int val : nums) {
            ++freq[val];
        }

        if (k == 1) {
            for (int id = 0; id < upLimit; id++) {
                if (freq[id] == 1) {
                    ans = max(ans, id);
                }
            }
            return ans;
        }

        if (k == n) {
            return upLimit - 1;
        }

        if (freq[nums.front()] == 1 && freq[nums.back()] == 1) {
            return max(nums.front(), nums.back());
        }

        if (freq[nums.front()] == 1) {
            return nums.front();
        }
        
        if (freq[nums.back()] == 1) {
            return nums.back();
        }
        
        return -1;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }
        int count[51] = {0};
        for (int x : nums) {
            count[x]++;
        }
        if (k == 1) {
            for (int i = 50; i >= 0; --i) {
                if (count[i] == 1) {
                    return i;
                }
            }
            return -1;
        }
        int res = -1;
        if (count[nums[0]] == 1) {
            res = max(res, nums[0]);
        }
        if (count[nums.back()] == 1) {
            res = max(res, nums.back());
        }
        return res;
    }
};
