/* Original Solution 1 */
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums.front();
        }

        constexpr int decimal = 10;
        vector<int> nextNums(n - 1, 0);

        for (int i = 0; i < n - 1; i++) {
            nextNums[i] = (nums[i] + nums[i + 1]) % decimal;
        }

        return triangularSum(nextNums);
    }
};


/* Original Solution 2 */
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        shared_ptr<int[]> sPtr(new int[n]);
        constexpr int decimal = 10;

        /* initialize the sPtr */
        for (int i = 0; i < n; i++) {
            sPtr[i] = nums[i];
        }

        for (int layer = 1; layer < n; layer++) {
            for (int i = 0; i < n - layer; i++) {
                sPtr[i] = (sPtr[i] + sPtr[i + 1]) % decimal;
            }
        }

        return sPtr[0];
    }
};





/* Original Solution 3 */
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        constexpr int decimal = 10;

        for (int layer = 1; layer < n; layer++) {
            for (int i = 0; i < n - layer; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % decimal;
            }
        }

        return nums.front(); 
    }
};



/* Official Solution 1 */
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> new_nums;
            for (int i = 0; i < nums.size() - 1; ++i) {
                new_nums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = move(new_nums);
        }
        return nums[0];
    }
};
