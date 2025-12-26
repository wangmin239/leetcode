/* Original Solution 1 */
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cntY = 0;
        int cntN = 0;
        int minTime = 0;
        int minCost;

        /* Calculate the total number of customers */
        for (char ch : customers) {
            if (ch == 'Y') {
                ++cntY;
            }
        }

        minCost = cntY;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                --cntY;
            } else {
                ++cntN;
            }
            /* update the minmum total */
            if (cntY + cntN < minCost) {
                minTime = i + 1;
                minCost = cntY + cntN;
            }
        }
        return minTime;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0, min_penalty = 0, ans = 0;
        for (int i = 0; i < customers.size(); i++) {
            penalty += customers[i] == 'N' ? 1 : -1;
            if (penalty < min_penalty) {
                min_penalty = penalty;
                ans = i + 1;
            }
        }
        return ans;
    }
};
