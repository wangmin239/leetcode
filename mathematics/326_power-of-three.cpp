/* Original Solution 1 */
class Solution {
public:
    bool isPowerOfThree(int n) {
       const int divisor = 3;
       
       if (n <= 0) {
           return false;
       }

       while (n > 1) {
           if (n % divisor != 0) {
               return false;
           }
           
           n /= divisor;
       }
       
       return true;
    }
};


/* Original Solution 2 */
class Solution {
public:
    bool isPowerOfThree(int n) {
       const int divisor = 3;
       
       if (n <= 0) {
           return false;
       }
       
       if (n == 1) {
           return true;
       }

       return (n % divisor == 0) && (isPowerOfThree(n / 3));
    }
};



/* Original Solution 3*/
class Solution {
public:
    bool isPowerOfThree(int n) {
       const int divisor = 3;
       long long multiply = 1;
       
       while (multiply < n) {
           multiply *= divisor;
       }
       
       return multiply == n;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

/* Official Solution 2 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
