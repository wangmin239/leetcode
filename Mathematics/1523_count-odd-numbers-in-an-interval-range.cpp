/* Original Solution 1 */
class Solution {
public:
    int countOdds(int low, int high) {

        return (high + 1) / 2 - low / 2;

    }
};

/* Official Solution 1 */
class Solution {
public:
    int pre(int x) {
        return (x + 1) >> 1;
    }
    
    int countOdds(int low, int high) {
        return pre(high) - pre(low - 1);
    }
};
