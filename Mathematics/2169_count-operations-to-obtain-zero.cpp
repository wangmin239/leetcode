/* Original Solution 1 */
class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0) {
            return 0;
        }

        if (num1 >= num2) {
            return 1 + countOperations(num1 - num2, num2);
        }
        
        return 1 + countOperations(num1, num2 - num1);
    }
};


/* Original Solution 2 */
class Solution {
public:
    int countOperations(int num1, int num2) {
        int steps = 0;
        
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ++steps;
        }
        
        return steps;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countOperations(int x, int y) {
        int ans = 0;
        while (y > 0) {
            ans += x / y;
            x %= y;
            swap(x, y);
        }
        return ans;
    }
};
