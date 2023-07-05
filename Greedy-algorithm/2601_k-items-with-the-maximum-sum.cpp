class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
       if (k <= numOnes) {
           return k;
       }
       
       if (k <= numOnes + numZeros) {
           return numOnes;
       }
       
       return numOnes - (k - numOnes - numZeros);
    }
};

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) {
            return k;
        } else if (k <= numOnes + numZeros) {
            return numOnes;
        } else {
            return numOnes - (k - numOnes - numZeros);
        }
    }
};

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return min(numOnes, k) - max(k - numOnes - numZeros, 0);
    }
};