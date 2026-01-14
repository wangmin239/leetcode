class Solution {
public:
    map<vector<int>, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();

        // 过滤不需要计算的大礼包，只保留需要计算的大礼包
        vector<vector<int>> filterSpecial;
        for (auto & sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, special, needs, filterSpecial, n);
    }

    // 记忆化搜索计算满足购物清单所需花费的最低价格
    int dfs(vector<int> price,const vector<vector<int>> & special, vector<int> curNeeds, vector<vector<int>> & filterSpecial, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; ++i) {
                minPrice += curNeeds[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
            }
            for (auto & curSpecial : filterSpecial) {
                int specialPrice = curSpecial[n];
                vector<int> nxtNeeds;
                for (int i = 0; i < n; ++i) {
                    if (curSpecial[i] > curNeeds[i]) { // 不能购买超出购物清单指定数量的物品
                        break;
                    }
                    nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
                }
                if (nxtNeeds.size() == n) { // 大礼包可以购买
                    minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpecial, n) + specialPrice);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};




class Solution {
public:
    bool checkRequires(const vector<int>& needs) {
        int n = needs.size();
        for (int i = 0; i < n; i++) {
            if (needs[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
    void backTrace(vector<int>& needs, int totalCost, const vector<vector<int>>& special, const vector<int>& price) {
        if (checkRequires(needs) == true) {
            ans = min(totalCost, ans);
            return;
        }
        int n = needs.size();
        for (const auto& package : special) {
            bool usedSpecial = true;
            for (int i = 0; i < n; i++) {
                if (package[i] > needs[i]) {
                    usedSpecial = false;
                    break;
                }
            }
            
            vector<int> tmp(needs);
            int mul = 10;
            if (needs.front() > 6) {
                if (usedSpecial == true) {
                    for (int i = 0; i < n; i++) {
                        if (package[i] != 0) {
                            mul = min(mul, tmp[i] / package[i]);
                        }
                    }

                    for (int i = 0; i < n; i++) {
                        tmp[i] -= mul * package[i];
                    }
                    backTrace(tmp, totalCost + package[n] * mul, special, price);
                }
            } else {
                if (usedSpecial == true) {
                    for (int i = 0; i < n; i++) {
                        tmp[i]  -= package[i];
                    }
                    backTrace(tmp, totalCost + package[n], special, price);
                }
            }                
    
        }
        
        /* Don't use any special bag */
        for (int i = 0; i < n; i++) {
            totalCost += needs[i] * price[i];
        }
      
        ans = min(ans, totalCost);
        return;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        
        ans = 0;
        for (int i = 0; i < n; i++) {
            ans += needs[i] * price[i];
        }

        backTrace(needs,  0, special, price);
        
        return ans;
    }
    
    int ans;
    
};