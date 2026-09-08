/* Original Solution 1 */
class Solution {
public:
    int countCommas(int n) {
        const int thousand = 1000;
        return n < thousand ? 0 : (n - thousand) + 1;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countCommas(int n) {
        return max(n - 999, 0);
    }
};

