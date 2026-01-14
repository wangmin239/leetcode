class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.emplace(prices[i]);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int discount = 0;
            for (int j = i + 1; j < n; ++j) {
                if(prices[j] <= prices[i]){
                    discount = prices[j];
                    break;
                }
            }
            ans.emplace_back(prices[i] - discount);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices);
        int size = prices.size();
        
        for (int i = 0; i < size - 1; i++) {
            int j = i + 1;
            while (j < size) {
                if (prices[j] <= prices[i]) {
                    ans[i] -= prices[j];
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};