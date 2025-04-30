/* Original Solution */
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> rabbits;
        
        for (int num : answers) {
            ++rabbits[num];
        }
        
        int ans = 0;
        
        for (auto [num, total] : rabbits) {
            if (num <= total) {
                int k = (total + num )/ (num + 1);
                ans += k * (num + 1);
            } else {
                ans += num + 1;
            }
        }
        
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> count;
        for (int y : answers) {
            ++count[y];
        }
        int ans = 0;
        for (auto &[y, x] : count) {
            ans += (x + y) / (y + 1) * (y + 1);
        }
        return ans;
    }
};