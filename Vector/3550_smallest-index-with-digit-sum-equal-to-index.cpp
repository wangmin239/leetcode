/* Official Solution 1 */
class Solution {
public:
    int smallestIndex(const std::vector<int>& nums) {
        auto getDigitSum = [](int num) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            return sum;
        };

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (getDigitSum(nums[i]) == i) {
                return i;
            }
        }

        return -1;
    }
};

/* Original Solution 1 */
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        const int decimal = 10;
        auto isEqual = [&](int index, int sum, auto&& self) {
            if (nums[index] == 0) {
                return sum == index;
            }

            sum += nums[index] % decimal;
            nums[index] /= decimal;

            return self(index, sum, self);
        };

        for (int i = 0; i < n; i++) {

            if (isEqual(i, 0, isEqual) == true) {
                return i;
            }
        }

        return -1;
    }
};

/* Original Solution 2 */
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        const int decimal = 10;

        for (int i = 0; i < n; i++) {

            int digitsSum = 0;

            while (nums[i]) {
                digitsSum += nums[i] % decimal;
                nums[i] /= decimal;
            }

            if (digitsSum == i) {
                return i;
            }
        }

        return -1;
    }
};