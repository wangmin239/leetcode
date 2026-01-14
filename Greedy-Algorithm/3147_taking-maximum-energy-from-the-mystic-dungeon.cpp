/* Original Solution 1 */
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
       int n = energy.size();
       int maxEnergy = INT_MIN;
       vector<int> energySum(k);


       /* Split an energy array into K groups */
       for (int i = 0; i < k; i++) {
           int curEnergy = 0;

           for (int j = i; j < n; j += k) {
               curEnergy += energy[j];
           }
           energySum[i] = curEnergy;
           maxEnergy = max(maxEnergy, curEnergy);
       }
       /* Subtract each element from one group */
       for (int i = 0; i < k; i++) {
           for (int j = i; j < n - k; j += k) {
               energySum[i] -= energy[j];
               maxEnergy = max(maxEnergy, energySum[i]);
           }

       }


       return maxEnergy;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = n - k; i < n; i++) { // 枚举终点 i
            int suf_sum = 0;
            for (int j = i; j >= 0; j -= k) {
                suf_sum += energy[j]; // 计算后缀和
                ans = max(ans, suf_sum);
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        for (int i = n - k - 1; i >= 0; i--) {
            energy[i] += energy[i + k];
        }
        return ranges::max(energy);
    }
};

/* Official Solution 3 */
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), ans = INT_MIN;
        for (int i = n - k; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
