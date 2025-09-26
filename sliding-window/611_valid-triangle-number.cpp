/* Official Solution 1 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                ans += k - j;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i + 1;
            for (int j = i + 1; j < n; ++j) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};


/* Original Solution  1 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        map<int, int> digits;
        auto checkValid = [](const int& a, const int& b, const int& c) {
            return a + b > c;
        };
        
    
        for (int num : nums) {
            ++digits[num];
        }
        
        int sum = 0;
        int len = digits.size();
        vector<int> lenVec(len, 0);
        int i = 0;
        
        for (const auto& [aLen, cnt] : digits) { 
            if (cnt > 2 && aLen != 0) {
                sum += cnt * (cnt - 1) * (cnt - 2) / 6;
            }
            lenVec[i++] = aLen;
        }

        for (const auto& [aLen, aCnt] : digits) {
            for (const auto& [bLen, bCnt] : digits) {
                if (aCnt > 1 && aLen != bLen) {
                    if (aLen < bLen && checkValid(aLen, aLen, bLen) == true ||
                        (aLen > bLen && checkValid(bLen, aLen, aLen) == true)) {
                            sum += aCnt * (aCnt - 1) * bCnt / 2;
                    }
                }
            }
        }

        for (int ia = 0; ia < len - 2; ia++) {
            for (int ib = ia + 1; ib < len - 1; ib++) {                 
                for (int ic= ib + 1; ic < len; ic++) {
                    int aLen = lenVec[ia];
                    int bLen = lenVec[ib];
                    int cLen = lenVec[ic];
                    if (checkValid(aLen, bLen, cLen) == true) {
                        sum += digits[aLen] * digits[bLen] * digits[cLen];
                    } else {
                        break;
                    }
                }
                
            }
        }
        return sum;
    }
};