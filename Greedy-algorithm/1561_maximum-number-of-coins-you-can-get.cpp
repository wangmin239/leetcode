/* Original Solution */
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int n = piles.size();

        sort(piles.begin(), piles.end(), greater<int>());
        
        for (int i = 1; i < n - n / 3; i += 2) {
            ans += piles[i];
        }
        
        return ans;
    }
};



/* Official Solution */
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int length = piles.size();
        int rounds = length / 3;
        int coins = 0;
        int index = length - 2;
        for (int i = 0; i < rounds; i++) {
            coins += piles[index];
            index -= 2;
        }
        return coins;
    }
};

