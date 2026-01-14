class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int res = 0;
        for (int i = 0; i < n; ++i){
            // 遍历计算每个人所需时间
            if (i <= k){
                res += min(tickets[i], tickets[k]);
            }
            else{
                res += min(tickets[i], tickets[k] - 1);
            }
        }
        return res;
    }
};




class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;

        for (int i = 0; i <= k; i++) {
            total += min(tickets[i], tickets[k]);
        }
        
        for (int i = k + 1; i < static_cast<int>(tickets.size()); i++) {
            total += min(tickets[i], tickets[k] - 1);
        }
        
        return total;
    }
};







class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        int cur = tickets[k] - 1;
        for (size_t i = 0; i < tickets.size(); i++) {
            int minVal = min(tickets[i], cur);
            total += minVal;
            tickets[i] -= minVal;
        }
        
        for (int i = 0; i <= k; i++) {
           total += min(tickets[i], 1); 
        }
        
        return total;
    }
};

