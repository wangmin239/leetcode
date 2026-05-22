/* Original Solution 1 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        auto getMinVal =[&]() {
            int left, right;
            for (left = 0, right = n - 1; left < right; ) {
                int mid = (left + right) / 2;

                if (nums[left] > nums[right]) {
                    if (nums[mid] > nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                } else {
                    right = mid;
                }
            }
            return left;
        };

        int minPos = getMinVal();

        if (target < nums[minPos]) {
            return -1;
        }

        if (minPos > 0 && target > nums[minPos - 1]) {
            return -1;
        }

        if (minPos == 0 && target > nums.back()) {
            return -1;
        }

        auto iter = lower_bound(nums.begin() + minPos, nums.end(), target);

        if (iter != nums.end() && *iter == target) {
            return iter - nums.begin();
        }

        iter = lower_bound(nums.begin(), nums.begin() + minPos, target);
        if (iter != nums.begin() + minPos && *iter == target) {
            return iter - nums.begin();
        }

        return -1;
    }
};




/* Original Solution 1 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minPos = min_element(nums.begin(), nums.end()) - nums.begin();

        if (target < nums[minPos]) {
            return -1;
        }

        auto iter = lower_bound(nums.begin() + minPos, nums.end(), target);

        if (iter != nums.end() && *iter == target) {
            return iter - nums.begin();
        }

        iter = lower_bound(nums.begin(), nums.begin() + minPos, target);
        if (iter != nums.begin() + minPos && *iter == target) {
            return iter - nums.begin();
        }

        return -1;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

