class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        int prevPrice = timePriceMap.count(timestamp) ? timePriceMap[timestamp] : 0;
        timePriceMap[timestamp] = price;
        if (prevPrice > 0) {
            auto it = prices.find(prevPrice);
            if (it != prices.end()) {
                prices.erase(it);
            }
        }
        prices.emplace(price);
    }
    
    int current() {
        return timePriceMap[maxTimestamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    multiset<int> prices;
};

typedef pair<int,int> pii;

class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        timePriceMap[timestamp] = price;
        pqMax.emplace(price, timestamp);
        pqMin.emplace(price, timestamp);
    }
    
    int current() {
        return timePriceMap[maxTimestamp];
    }
    
    int maximum() {
        while (true) {
            int price = pqMax.top().first, timestamp = pqMax.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMax.pop();
        }
    }
    
    int minimum() {
        while (true) {
            int price = pqMin.top().first, timestamp = pqMin.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMin.pop();
        }
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    priority_queue<pii, vector<pii>, less<pii>> pqMax;
    priority_queue<pii, vector<pii>, greater<pii>> pqMin;
};


class StockPrice {
public:
    StockPrice() {
        maxPrice = INT_MIN;
        minPrice = INT_MAX;
        curTime = 0;
    }
    
    void update(int timestamp, int price) {
        /* Case 1,  add new timestamp that is greater than the current timestamp */
        if (timestamp > curTime) {
            maxPrice = max(maxPrice, price);
            minPrice = min(minPrice, price);
            curTime = timestamp;
            stockPrice[timestamp] = price;
            return ;
        }
        /* Case 2, the price of the previous timestamp  isn't equal to either maximum or minimum */
        int prevPrice = stockPrice[timestamp];
        stockPrice[timestamp] = price;
        if (maxPrice != prevPrice && minPrice != prevPrice) {
            maxPrice = max(maxPrice, price);
            minPrice = min(minPrice, price);
            return ;
        }

      
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        for (auto [_, val] : stockPrice) {
            maxVal = max(maxVal, val);
            minVal = min(minVal, val);
        }
        maxPrice = maxVal;
        minPrice = minVal;
        
    }
    
    int current() {
        return stockPrice[curTime];
    }
    
    int maximum() {
        return maxPrice;
    }
    
    int minimum() {
        return minPrice;
    }
    int maxPrice;
    int minPrice;
    int curTime;
    unordered_map<int, int> stockPrice;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */