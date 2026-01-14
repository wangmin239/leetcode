class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>>  menus {{"Table"}};
        map<string, map<string, int>> recipes;
        
        for (auto& vec : orders) {
            auto recipe = vec[2];
            auto tableId = vec[1];
            if (recipes.count(recipe) > 0) {
                if (recipes[recipe].count(tableId) > 0) {
                    ++recipes[recipe][tableId];
                } else {
                    recipes[recipe][tableId] = 1;
                }
            } else {
                recipes[recipe][tableId] = 1;
            }
        }
        auto cmp = [](const auto& lhs, const auto& rhs) -> bool {
            auto first = stoi(lhs);
            auto second = stoi(rhs);
            return first < second;
        };
        map<string, vector<pair<string, int>>, decltype(cmp)> tableMenus(cmp);
        
        for (auto& [recipe, subMap]: recipes) {
            menus.back().push_back(recipe);
            for(auto& [tableId, num]: subMap) {
                tableMenus[tableId].emplace_back(recipe, num);
            }
        }
        
        for (auto& [tableId, vec]: tableMenus) {
            menus.emplace_back(vector<string> {tableId});
            for (auto& [recipe, _]: recipes) {
                bool match = false;
                for (int i = 0; i < vec.size(); ++i) {
                    if (recipe == vec[i].first) {
                        menus.back().push_back(to_string(vec[i].second));
                        match = true;
                        break;
                    } 
                }
                
                if (match == false) {
                    menus.back().push_back("0");
                }
            }       
        }
        return menus;
    }
};


class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        // 从订单中获取餐品名称和桌号，统计每桌点餐数量
        unordered_set<string> nameSet;
        unordered_map<int, unordered_map<string, int>> foodsCnt;
        for (auto &order : orders) {
            nameSet.insert(order[2]);
            int id = stoi(order[1]);
            ++foodsCnt[id][order[2]];
        }

        // 提取餐品名称，并按字母顺序排列
        int n = nameSet.size();
        vector<string> names;
        for (auto &name : nameSet) {
            names.push_back(name);
        }
        sort(names.begin(), names.end());

        // 提取桌号，并按餐桌桌号升序排列
        int m = foodsCnt.size();
        vector<int> ids;
        for (auto &[id, _] : foodsCnt) {
            ids.push_back(id);
        }
        sort(ids.begin(), ids.end());

        // 填写点菜展示表
        vector<vector<string>> table(m + 1, vector<string>(n + 1));
        table[0][0] = "Table";
        copy(names.begin(), names.end(), table[0].begin() + 1);
        for (int i = 0; i < m; ++i) {
            int id = ids[i];
            auto &cnt = foodsCnt[id];
            table[i + 1][0] = to_string(id);
            for (int j = 0; j < n; ++j) {
                table[i + 1][j + 1] = to_string(cnt[names[j]]);
            }
        }
        return table;
    }
};
