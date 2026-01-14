/* Original Solution 1, The code failed to pass all testsuits */
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        map<int, int> numMap;
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());

        right -= *min_element(nums.begin(), nums.end());
        for (int num : nums) {
            ++numMap[num];
        }
        
        while (left < right) {
            int mid = (left + right) / 2;
            auto prevIter = numMap.begin();
            int total = prevIter->second;
            auto iter = prevIter;

            for (++iter; iter != numMap.end(); ++iter) {
                if (iter->first - prevIter->first <= mid) {
                    total += iter->second;
                } else {
                    total += 2 *(iter->second / 2);
                }  
                prevIter = iter;
            }

            
            if (total >= 2 * p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        auto check = [&](int mx) -> bool {
            int cnt = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i + 1] - nums[i] <= mx) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= p;
        };
        int left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
