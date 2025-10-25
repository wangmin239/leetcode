/* Original Solution 1 */
class Solution {
public:
    int totalMoney(int n) {
        if (n == 1) {
            return 1;
        }

        const int weekDays = 7;
        return (n + weekDays - 1) / weekDays + (n - 1) % weekDays + totalMoney(n - 1);
    }
};



/* Original Solution 2 */
class Solution {
public:
    int totalMoney(int n) {
        const int weekDays = 7;
        int weeks = n / weekDays;
        int days = n % weekDays;
        int sum = 0;
        
        sum += weeks * (1 + weekDays) * weekDays / 2  +  weekDays * (weeks - 1) * weeks / 2;
        sum += days * weeks;
        sum += (1 + days) * days / 2;
        
        
        return sum;
    }
};