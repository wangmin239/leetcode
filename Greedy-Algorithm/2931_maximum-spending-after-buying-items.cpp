class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values[0].size();
        priority_queue<ti3, vector<ti3>, greater<ti3>> q;
        for (int i = 0; i < m; ++i) {
            q.emplace(values[i][n - 1], i, n - 1);
        }
        long long ans = 0;
        for (int turn = 1; turn <= m * n; ++turn) {
            auto [val, i, j] = q.top();
            q.pop();
            ans += static_cast<long long>(val) * turn;
            if (j > 0) {
                q.emplace(values[i][j - 1], i, j - 1);
            }
        }
        return ans;
    }

private:
    using ti3 = tuple<int, int, int>;
};





class Solution {
public:
    long long maxSpending(const vector<vector<int>> &values) {
        long long ans = 0;
        const int shopsNum = static_cast<int>(values.size());
        const int itemsNum = static_cast<int>(values[0].size());
        vector<int> shops(shopsNum, itemsNum - 1);

        for (int day = 1; day <= shopsNum * itemsNum; ++day) {
            int shopId = 0;
            int minCost = INT_MAX;
            for (int i = 0; i < shopsNum; ++i) {
                /* All the items of the shop are sold out. */
                if (shops[i] < 0) {
                    continue;
                }
                
                /* get the mininal value by comparing every shop's items */
                if (values[i][shops[i]] < minCost) {
                    minCost = values[i][shops[i]];
                    shopId = i;
                }
            }

            ans += minCost * day;
            --shops[shopId];
        }

        return ans;
    }
};



class Solution {
public:
    long long maxSpending(vector<vector<int>> &values) {
        long long ans = 0, d = 1;

        int m = static_cast<int>(values.size());
        while (m != 0) {
            int shop = 0, minCost = INT_MAX;
            for (int i = 0; i < m; ++i) {
                if (values[i].back() < minCost) {
                    minCost = values[i].back();
                    shop = i;
                }
            }
            ans += minCost * d++;

            values[shop].pop_back();
            if (values[shop].empty()) {
                if (shop != --m) swap(values[shop], values.back());
                values.pop_back();
            }
        }
        
        return ans;
    }
};




class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        typedef long long ll;
        typedef pair<int,int> pii;
    
        int m = values.size(), n = values[0].size();

        priority_queue<pii,vector<pii>,greater<pii>>q;
    
        vector<int>pointers(m, n - 2);

        for(int i = 0; i < m; i ++){
            q.push({values[i][pointers[i] + 1], i});
        }
        ll d = 1, res = 0;
        while(q.size()){
            pii t = q.top();
            q.pop();
            res += d * t.first;
            d ++;
            int idx = t.second;
            if(pointers[idx] >= 0){
                q.push({values[idx][pointers[idx]], idx});
                pointers[idx] --;   
            }
        }


        return res;

    }
};