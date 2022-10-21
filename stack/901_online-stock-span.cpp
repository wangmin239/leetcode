class StockSpanner {
public:
    StockSpanner() {
        this->stk.emplace(-1, INT_MAX);
        this->idx = -1;
    }
    
    int next(int price) {
        idx++;
        while (price >= stk.top().second) {
            stk.pop();
        }
        int ret = idx - stk.top().first;
        stk.emplace(idx, price);
        return ret;
    }

private:
    stack<pair<int, int>> stk; 
    int idx;
};





class StockSpanner {
public:
    StockSpanner() {
        priceVec.push_back(INT_MAX);
        curDays = 0;
    }
    
    int next(int price) {
        if (price < priceVec.back()) {
            priceVec.push_back(price);
            curDays = 1;
            return curDays;
        }
        
        if (price == priceVec.back()) {
            priceVec.push_back(price);
            return ++curDays;
        }
        curDays = 1;
        for (auto rIter = priceVec.rbegin(); rIter != priceVec.rend(); ++rIter) {
            if (*rIter < price) {
                curDays++;
            } else {
                break;
            }
        }
        priceVec.push_back(price);
        return curDays;
        
    }
private:
    vector<int> priceVec;
    int curDays;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */