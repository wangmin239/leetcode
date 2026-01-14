/* Original Solution 1 */
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> cntMod(value, 0);
        /* Count the frequency of each element's remainder in a number array */
        for (int i = 0; i < n; i++) {
            /* Ensure that every remainder is a positive value */
            int id = nums[i] % value + value;
            
            id = id % value;
            ++cntMod[id];
        }
        /* Search the first element with the smallest value in the array. */
        auto iter = min_element(cntMod.begin(), cntMod.end());
        int  id = iter - cntMod.begin();
        
        return *iter * value + id;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        for (auto &x : nums) {
            int v = (x % value + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
};


/* Official Solution 2*/
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int m) {
        vector<int> cnt(m);
        for (int x : nums) {
            cnt[(x % m + m) % m]++;
        }

        int i = ranges::min_element(cnt) - cnt.begin();
        return m * cnt[i] + i;
    }
};