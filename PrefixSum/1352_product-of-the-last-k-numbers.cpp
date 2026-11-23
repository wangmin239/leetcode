/* Original Solution 1 */
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        id = 0;
        digitCnt.resize(upLimit);
    }

    void add(int num) {
        digitCnt[num].push_back(id++);
    }

    int getProduct(int k) {
        int val = 1;
        int lowId = id - k;


        for (int num = 0; num < upLimit; num++) {
            int n = digitCnt[num].size();

            for (int index = n - 1; index >= 0; index--) {
                int id = digitCnt[num][index];
                if (id < lowId) {
                    break;
                }
                val *= num;
            }

            if (val == 0) {
                break;
            }
        }

        return val;
    }
    const static int upLimit = 104;
    vector<vector<int>> digitCnt;
    int id;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


/* Original Solution 1 */
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        multply = 1;
        preMultply.push_back(multply);
    }

    void add(int num) {
        multply *= num;
        preMultply.push_back(multply);
        
        if (num == 0) {
            multply = 1;
            fill(preMultply.begin(), preMultply.end(), 0);
        }
    }

    int getProduct(int k) {
        int n = preMultply.size();
        int id = n - k - 1;
        
        if (preMultply[id] == 0) {
            if (preMultply[id + 1] == 0) {
                return 0;
            }
            return preMultply.back();
        }
        
        return preMultply.back() / preMultply[id];
    }
    int multply;
    vector<int> preMultply;
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
 
 
 /* Official Solution 1 */
 class ProductOfNumbers {
private:
    vector<int> prefixProduct;
    
public:
    ProductOfNumbers() {
        prefixProduct.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
        } else {
            prefixProduct.push_back(num * prefixProduct.back());
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (n <= k) {
            return 0;
        }
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
 

/* Official Solution 2 */
class ProductOfNumbers {
private:
    vector<int> nums;    
    vector<int> zeroCount; 
    vector<int> prevNonOne;
    int n;                
    
public:
    ProductOfNumbers() {
        nums.clear();
        zeroCount.clear();
        prevNonOne.clear();
        n = 0;
    }
    
    void add(int num) {
        n++;
        nums.push_back(num);
        
        prevNonOne.push_back(-1);
        if (n > 1) {
            if (nums[n-2] != 1 && nums[n-2] != 0) {
                prevNonOne[n-1] = n-2;
            } else {
                prevNonOne[n-1] = prevNonOne[n-2];
            }
        }
        
        zeroCount.push_back(num == 0 ? 1 : 0);
        if (n > 1) {
            zeroCount[n-1] += zeroCount[n-2];
        }
    }
    
    int getProduct(int k) {
        int totalZeros = zeroCount[n-1];
        if (n - k >= 1) {
            totalZeros -= zeroCount[n-1-k];
        }
        if (totalZeros > 0) {
            return 0;
        }
        
        int ans = 1;
        for (int i = n - 1; i >= n - k; ) {
            ans *= nums[i];
            i = prevNonOne[i];
        }
        return ans;
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */