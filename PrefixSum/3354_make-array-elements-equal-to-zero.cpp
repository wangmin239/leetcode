/* Original Solution 1, Timeout*/
class Solution {
public:
    typedef enum tagDir {
        RIGHT = 0,
        LEFT = 1,
    } Dir;

    int countValidSelections(vector<int>& nums) {
        int methods = 0;
        int n = nums.size();
        auto allAreZero = [](vector<int>& tmpNums) {
            for (int num : tmpNums) {
                if (num != 0) {
                    return 0;
                }
            }
            return 1;
        };
        
        function<int(int, Dir, vector<int>&)> isValidSelection = [&n, &allAreZero, &isValidSelection](int id,
                Dir direction, vector<int>& tmpNums) {
            if (id < 0 || id >= n || tmpNums[id] < 0) {
                return allAreZero(tmpNums);
            }
            
            if (tmpNums[id] == 0) {
                if (direction == RIGHT) {
                    return isValidSelection(id + 1, RIGHT, tmpNums);
                }
                
                return isValidSelection(id - 1, LEFT, tmpNums);
            }
            
            tmpNums[id] -= 1;
            direction = static_cast<Dir>(!direction);
            if (direction == RIGHT) {
                return isValidSelection(id + 1, RIGHT, tmpNums);
            }
           
            return isValidSelection(id - 1, LEFT, tmpNums);

        };
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                vector<int> rightNums(nums);
                vector<int> leftNums(nums);
                methods += isValidSelection(i + 1, RIGHT, rightNums);
                methods += isValidSelection(i - 1, LEFT, leftNums);
            }
        }
        
        return methods;
    }
};

/* Original Solution 2 */
class Solution {
public:
    typedef enum tagDirections {
        ZERO = 0,
        SINGLE = 1,
        DUAL = 2,
        MAX
    } Dirs;
    
    int countValidSelections(vector<int>& nums) {
        int methods = 0;
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0, curSum = 0;
        
        for (int i = 0; i < n; i++, preSum = curSum) {
            /* Update the vector's prefix sum */
            curSum = preSum + nums[i];
            if (nums[i] == 0) {
                int doublePreSum = 2 * preSum;
                if (total == doublePreSum) {
                    methods += static_cast<int>(DUAL);
                } else if (abs(doublePreSum - total) == 1) {
                    methods += static_cast<int>(SINGLE);
                }
            }
        }
        
        return methods;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = reduce(nums.begin(), nums.end());
        int ans = 0, pre = 0;
        for (int x : nums) {
            if (x) {
                pre += x;
            } else if (pre * 2 == total) {
                ans += 2;
            } else if (abs(pre * 2 - total) == 1) {
                ans++;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int count = 0;
        int nonZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                nonZeros++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, nonZeros, i, -1)) {
                    count++;
                }
                if (isValid(nums, nonZeros, i, 1)) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isValid(const vector<int>& nums, int nonZeros, int start,
                 int direction) {
        int n = nums.size();
        vector<int> temp(nums);
        int curr = start;

        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0) {
                    nonZeros--;
                }
            }
            curr += direction;
        }

        return nonZeros == 0;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1){
                    ans++;
                }
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1){
                    ans++;
                }
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
        return ans;
    }
};
