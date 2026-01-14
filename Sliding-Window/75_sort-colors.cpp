




/* Original Solution 1 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n;

        
        for (int i = 0; i < right; i++) {            
            if (nums[i] == 0 || nums[i] == 1) {
                nums[left] = nums[i];
                left += static_cast<int>(!nums[i]);
                continue;
            }
            
            swap(nums[i--], nums[--right]);

        }

        fill_n(nums.begin() + left, right - left, 1);
        
        return ;
    }
};


/* Original Solution 2 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[left++] = 0;
            }
            
            if (nums[i] == 2) {
                ans[right--] = 2;
            }
        }
        
        nums = ans;
    }
};


/* Original Solution 3 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        
        for (int i = 1; i < n; i++) {
            int tmp = nums[i];
            int j = i - 1;
            
            while (j >= 0 && tmp < nums[j]) {
                 nums[j + 1] = nums[j];
                 j--;
            }
            
            nums[j + 1] = tmp;
            
        }
        
        return ;
    }
};


/* Original Solution 4 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        function<void(int, int)> mergeSort = [&](int left, int right) {
            if (left == right) {
                return;
            }
            
            if (right - left == 1) {
                if (nums[left] > nums[right]) {
                    swap(nums[left], nums[right]);
                }
                return;
            }
            
            int mid = (left + right) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            
            vector<int> tmp(right - left + 1);
            int front = left;
            int back = mid + 1;
            size_t i;
            
            for (i = 0; i < tmp.size(); i++) {
                if (nums[front] < nums[back]) {
                    tmp[i] = nums[front++];
                } else {
                    tmp[i] = nums[back++];
                }
                
                if (front == mid + 1 || back > right) {
                    i++;
                    break;
                }
            }
            
            while (front < mid + 1) {
                tmp[i++] = nums[front++];
            }
            
            while (back <= right) {
                tmp[i++] = nums[back++];
            }
            
            for (i = 0; i < tmp.size(); i++) {
                nums[left + i] = tmp[i];
            }
            
        };
        
        mergeSort(0, n - 1);
        
        return ;
    }
};

/* Official Solution 1 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};

/* Official Solution 2 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

/* Official Solution 3 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};


