/* Original Solution 1 */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxVal = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxVal + 1, 0);
        int num = 0;

        for (int coin : costs) {
            ++freq[coin];
        }


        for (int i = 1; i <= maxVal && coins > 0; i++) {
            int cnt = coins / i;

            if (cnt == 0) {
                break;
            }

            cnt = min(cnt, freq[i]);
            num += cnt;
            coins -= i * cnt;
        }

        return num;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int num = 0;

        sort(costs.begin(), costs.end());

        for (int cost : costs) {
            if (coins < cost) {
                break;
            }

            coins -= cost;
            ++num;
        }

        return num;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001);
        for (int& cost : costs) {
            freq[cost]++;
        }
        int count = 0;
        for (int i = 1; i <= 100000; i++) {
            if (coins >= i) {
                int curCount = min(freq[i], coins / i);
                count += curCount;
                coins -= i * curCount;
            } else {
                break;
            }
        }
        return count;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        int n = costs.size();
        for (int i = 0; i < n; i++) {
            int cost = costs[i];
            if (coins >= cost) {
                coins -= cost;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
