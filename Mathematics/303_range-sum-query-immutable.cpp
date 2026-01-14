class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};



class NumArray {
public:
    int *p;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        p = new int[n + 1] {0};

        
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return p[right + 1] - p[left];
    }
    
    ~NumArray() {
        delete [] p;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */



class NumArray {
public:
    unique_ptr<int []> pArr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pArr = make_unique<int[]>(n + 1);
        int *p = pArr.get();
        
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int *p = pArr.get();
        return p[right + 1] - p[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */