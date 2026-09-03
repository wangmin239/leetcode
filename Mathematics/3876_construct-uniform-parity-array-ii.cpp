/* Original Solution 1 */
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int n = nums1.size();

        for (int val : nums1) {
            if (val & 0x1) {
                minOdd = min(minOdd, val);
            }
        }

        auto checkInvalid = [&nums1, n](int createOdd, int minVal) {
            bool isValid = true;

            for (int i = 0; i < n; i++) {
                if ((nums1[i] & 0x1) == createOdd) {
                    continue;
                }

                if (nums1[i] - minVal < 1) {
                    isValid = false;
                    break;
                }
            }

            return isValid;
        };

        bool isOdd = checkInvalid(1, minOdd);
        bool isEven = checkInvalid(0, minOdd);

        return isOdd || isEven;
    }
};



/* Original Solution 2 */
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX - 1;
        int oddCnt = 0;
        int n = nums1.size();

        for (int val : nums1) {
            if (val & 0x1) {
                minOdd = min(minOdd, val);
                ++oddCnt;
            } else {
                minEven = min(minEven, val);
            }
        }

        return oddCnt == n || oddCnt == 0 || minOdd < minEven;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool hasOdd = false;
        for (int v : nums1) {
            if (v < mn) {
                mn = v;
            }
            if (v & 1) {
                hasOdd = true;
            }
        }
        if (mn & 1) {
            return true;
        }
        return !hasOdd;
    }
};

/* Official Solution 2 */
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // 计算最小偶数、最小奇数
        int mn[2] = {INT_MAX, INT_MAX};
        for (int x : nums1) {
            mn[x & 1] = min(mn[x & 1], x); // &1 比 %2 好，nums1 有负数也适用
        }

        // 只有偶数，或者偶数 >= 最小的偶数 > 最小的奇数
        // 只有奇数的情况蕴含在 mn[0] > mn[1] 中
        return mn[1] == INT_MAX || mn[0] > mn[1];
    }
};
