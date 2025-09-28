/* Original Solution 1 */
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int len = nums.size();
        int maxLen = 0;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int i = 0; i < len - 2; i++) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return accumulate(nums.begin() + i, nums.begin() + i + 3, 0);
            }
        }
        
        return 0;

    }
};



/* Original Solution 2 */
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int len = nums.size();
        int maxLen = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < len - 1; j++) {
                while (k < len && nums[k] < nums[i] + nums[j]) {
                    ++k;
                }
                
                if (k > j + 1) {
                    maxLen = nums[i] + nums[j] + nums[k - 1];
                }
            }
        }
        
        return maxLen;

    }
};


/* Original Solution 3 */
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int len = nums.size();
        int maxLen = 0;
        
        sort(nums.begin(), nums.end());
        
        /* Use binary Search to check if three line segments of arbitrary lengths form a triangle */
        auto getMax = [](const vector<int>& nums, int end) {
            for (int left = 0, right = end - 1; left + 1 < right; ) {
                int mid = (left + right) / 2;

                if (nums[left] + nums[mid] <= nums[right]) {
                    left = mid;
                } else {
                    if (right - left > 1) {
                        return accumulate(nums.begin() + right - 2, nums.begin() + right + 1, 0);
                    }
                    break;
                }
            }
            return 0;
        };
        /* Select the second longest segment from the given array as the longest edge of the triangle. */        
        for (int end = len;  end > 2; end--) {
            maxLen = getMax(nums, end);
            
            if (maxLen != 0) {
                return maxLen;
            }
        }
        
        return maxLen;

    }
};

/* Official Solution 1 */
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = (int)nums.size() - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};
