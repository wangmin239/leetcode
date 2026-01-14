class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int findNum = nums[0];
        int i = 0;
        while (i < len - 1) {
            if (nums[i] == nums[i + 1]) {
                i += 2;
            } else {
                findNum = nums[i];
                break;
            }
        }
        
        if (i == len - 1) {
            findNum = nums[i];
        }
        
        return findNum;
    }
};



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            mid -= mid & 1;
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};
