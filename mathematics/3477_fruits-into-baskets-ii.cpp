/* Original Solution 1 */
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int remain = 0;
        int n = fruits.size();
        vector<bool> isUsed(n, false);
        
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (isUsed[j] == false && baskets[j] > fruits[i]) {
                    isUsed[j] = true;
                    break;
                }
            }
            
            if (j == n) {
                ++remain;
            }
        }
        
        return remain;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = baskets.size();
        for (auto fruit : fruits) {
            int unset = 1;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            count += unset;
        }
        return count;
    }
};
