class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }
        int increase = 0;
        for (int i = 0; i < minutes; i++) {
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for (int i = minutes; i < n; i++) {
            increase = increase - customers[i - minutes] * grumpy[i - minutes] + customers[i] * grumpy[i];
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
};

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxRange = 0;
        int sum = 0;
        int eachRange = 0;
        
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                eachRange += customers[i];
            } else {
                sum += customers[i];
            }
        }
        maxRange = eachRange;
        for (int i = minutes; i < n; i++) {
            eachRange = eachRange - customers[i - minutes] * grumpy[i - minutes] + customers[i] * grumpy[i];
            maxRange = max(eachRange, maxRange);
            sum += grumpy[i] == 0 ? customers[i] : 0;
        }
        

        
        return sum + maxRange;
    }
};


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int minRange = 0;
        int sum = 0;
        
        for (int i = 0; i <= n - minutes; i++) {
            int eachRange = 0;
            for (int k = i; k < i + minutes; k++) {
                if (grumpy[k] == 1) {
                    eachRange -= customers[k];
                }
            }
            
            if (eachRange < minRange) {
                minRange = eachRange;
            }
            
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        
        for (int i = n - minutes + 1; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        
        return sum - minRange;
    }
};