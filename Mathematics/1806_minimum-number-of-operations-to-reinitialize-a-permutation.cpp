class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) {
            return 1;
        }
        int step = 1, pow2 = 2;
        while (pow2 != 1) {
            step++;
            pow2 = pow2 * 2 % (n - 1);
        }
        return step;
    }
};




class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n), target(n);
        iota(perm.begin(), perm.end(), 0);
        iota(target.begin(), target.end(), 0);
        int step = 0;
        while (true) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                } else {
                    arr[i] = perm[i / 2];
                }
            }
            perm = move(arr);
            step++;
            if (perm == target) {
                break;
            }
        }
        return step;
    }
};




class Solution {
public:
    int reinitializePermutation(int n) {
        unique_ptr<int[]> perm(new int [n]);
        unique_ptr<int[]> arr(new int [n]);

        /* initizlization */
        int* ptrP = perm.get();
        for (int i = 0; i < n; i++) {
            ptrP[i] = i;
        }
        int steps = 0;
        int* ptrA = arr.get();
        
        do {
            operation(ptrP, ptrA, n);
            ++steps;
            assignPerm(ptrP, ptrA, n);
        } while (comp(ptrA, n) != true);

        return steps;
    }
    
    void operation(int* ptrP, int* ptrA, int n) {
        for (int i = 0; i < n; i++) {
            if ((i & 0x1) == 0) {
              ptrA[i] = ptrP[i / 2];   
            } else {
               ptrA[i] = ptrP[n / 2 + (i - 1) / 2]; 
            }
        }
        
        return;
    }
    
    void assignPerm(int* ptrP, int* ptrA, int n) {
        for (int i = 0; i < n; i++) {
            ptrP[i] = ptrA[i];
        }
    }
    
    bool comp(int* ptrA, int n) {
        for (int i = 0; i < n; i++) {
            if (ptrA[i] != i) {
                return false;
            }
        }
        return true;
    }
};