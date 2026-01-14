/* Official Solution */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int x : nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                st.insert(x);
            }
        }
        return st.size();
    }
};



/* Original Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minSteps = 0;
        const int total = 101;
        int arr[total] = {0};
        int minVal = *min_element(nums.begin(), nums.end());
        
        if (minVal < k) {
            return -1;
        }
        
        for(int value : nums) {
            arr[value] = 1;
        }
        
        minSteps = accumulate(arr, arr + total, 0);
        
        if (minVal == k) {
            --minSteps;
        }
        
        return minSteps;
    }
};

/* Original Solution 2 */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n =  nums.size();
        int minSteps = 0;
        unordered_set<int> numSet;
        int minVal = *min_element(nums.begin(), nums.end());
        
        if (minVal < k) {
            return -1;
        }
        
        for(int value : nums) {
            if (numSet.count(value) == 0) {
                numSet.insert(value);
            }
        }
        
        minSteps = numSet.size();
        
        if (minVal == k) {
            --minSteps;
        }
        
        return minSteps;
    }
};


/* Original Solution 3 */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n =  nums.size();
        int steps = 0;
        
        sort(nums.begin(), nums.end(), greater<int>());

        if (nums.back() < k) {
            return -1;
        }
        

        for (int left = 0, right = 1; right < n; right++) {
            if (nums[left] != nums[right]) {
                ++steps;
                left = right;
            }
        }
        
        return steps += static_cast<int>(nums.back() != k);
    }
};
