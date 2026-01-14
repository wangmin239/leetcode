class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
};


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int x = (n + 1) / 2;
        int mid = x - 1;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[k] > nums[mid]) {
                while (j > k && nums[j] > nums[mid]) {
                    j--;
                }
                swap(nums[k], nums[j--]);
            }
            if (nums[k] < nums[mid]) {
                swap(nums[k], nums[i++]);
            }
        }
        vector<int> arr = nums;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
};

class Solution {
public:
    inline int transAddress(int i, int n) {
        return (2 * n - 2 * i - 1) % (n | 1);
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int x = (n + 1) / 2;
        int mid = x - 1;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int target = nums[mid];
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[transAddress(k, n)] > target) {
                while (j > k && nums[transAddress(j, n)] > target) {
                    j--;
                }
                swap(nums[transAddress(k, n)], nums[transAddress(j--, n)]);
            }
            if (nums[transAddress(k, n)] < target) {
                swap(nums[transAddress(k, n)], nums[transAddress(i++, n)]);
            }
        }
    }
};


class Solution {
public:
    int partitionAroundPivot(int left, int right, int pivot, vector<int> &nums) {
        int pivotValue = nums[pivot];
        int newPivot = left;
        swap(nums[pivot], nums[right]);
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivotValue) {
                swap(nums[i], nums[newPivot++]);
            }
        }
        swap(nums[right], nums[newPivot]);
        return newPivot;
    }

    int findKthLargest(vector<int> &nums, int k) {
        int left = 0, right = nums.size() - 1;
        default_random_engine gen((random_device())());
        while (left <= right) {
            uniform_int_distribution<int> dis(left, right);
            int pivot = dis(gen);
            int newPivot = partitionAroundPivot(left, right, pivot, nums);
            if (newPivot == k - 1) {
                return nums[newPivot];
            } else if (newPivot > k - 1) {
                right = newPivot - 1;
            } else { 
                left = newPivot + 1;
            }
        }
        return nums[k - 1];
    }

    inline int transAddress(int i, int n) {
        return (2 * n - 2 * i - 1) % (n | 1);
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int x = (n + 1) / 2;
        int mid = x - 1;
        int target = findKthLargest(nums, n - mid);
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[transAddress(k, n)] > target) {
                while (j > k && nums[transAddress(j, n)] > target) {
                    j--;
                }
                swap(nums[transAddress(k, n)], nums[transAddress(j--, n)]);
            }
            if (nums[transAddress(k, n)] < target) {
                swap(nums[transAddress(k, n)], nums[transAddress(i++, n)]);
            }
        }
    }
};


