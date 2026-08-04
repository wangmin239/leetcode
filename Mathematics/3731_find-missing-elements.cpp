/* Official Solution 1 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = nums.front() + 1, j = 1; i < nums.back(); i++) {
            if (i < nums[j]) {
                ans.push_back(i);
            } else {
                j++;
            }
        }

        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.back() - nums.front() + 1 - n);
        int id = 0;
        
        for (int i = nums.front() + 1, j = 1; i < nums.back(); i++) {
            if (i < nums[j]) {
                ans[id++] = i;
                continue;
            }
            
            j++;
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int mn = ranges::min(nums);
        int mx = ranges::max(nums);
        vector<int> ans;
        for (int i = mn + 1; i < mx; i++) {
            if (!st.contains(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
