/* Original Solution 1 */
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int right;
        
        for (right = 0; right < n; ++right) {

            if (nums[right] - nums[0] == right) {
                sum += nums[right];
            } else {
                break;
            }
        }

        right == n ? --right : right;
        sort(nums.begin() + right, nums.end());

        sum == nums.front() ? ++sum : sum;
        while (right < n) {
            if (sum >= nums[right]) {    
                sum == nums[right]? ++sum: sum;
                ++right;
            } else {
                break;
            }
        }

        return sum;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int right = 0; right < n; ++right) {

            if (nums[right] - nums[0] == right) {
                sum += nums[right];
            } else {
                break;
            }
        }

        unordered_set<int> numSet(nums.begin(), nums.end());

        while (numSet.count(sum) != 0) {
            ++sum;
        }


        return sum;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int total = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }

        while (num_set.count(total)) {
            total += 1;
        }

        return total;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int prefix_len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_len += 1;
            } else {
                break;
            }
        }

        int total = (nums[prefix_len - 1] + nums[0]) * prefix_len / 2;
        while (num_set.count(total)) {
            total += 1;
        }

        return total;
    }
};
