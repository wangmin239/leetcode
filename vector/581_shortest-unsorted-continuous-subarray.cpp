class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> backVec(nums);
        int size = nums.size();
        int commonCnt;
        
        sort(backVec.begin(), backVec.end());
        for (commonCnt = 0; commonCnt < size; commonCnt++) {
            if (backVec[commonCnt] != nums[commonCnt]) {
                break;
            }
        }
        
        for (int i = size - 1; i > commonCnt; i--) {
            if (backVec[i] != nums[i]) {
                commonCnt += size - i - 1;
                break;
            }
        }
        
        return size - commonCnt;
    }
};



class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        int left = 0;
        while (nums[left] == numsSorted[left]) {
            left++;
        }
        int right = nums.size() - 1;
        while (nums[right] == numsSorted[right]) {
            right--;
        }
        return right - left + 1;
    }
};


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) {
                right = i;
            } else {
                maxn = nums[i];
            }
            if (minn < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};
