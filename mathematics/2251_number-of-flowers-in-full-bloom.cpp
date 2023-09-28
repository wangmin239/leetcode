class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        unordered_map<int, int> flowerNum;
        
        for (const auto& flower : flowers) {
            for (int i = flower.front(); i <= flower.back(); i++) {
                ++flowerNum[i];
            }
        }
        
        int n = people.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int time = people[i];
            ans[i] = flowerNum[time];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        int n = flowers.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int m = persons.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int x = upper_bound(starts.begin(), starts.end(), persons[i]) - starts.begin();
            int y = lower_bound(ends.begin(), ends.end(), persons[i]) - ends.begin();
            ans[i] = x - y;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        for (auto &flower : flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int m = persons.size();
        vector<int> indices(m);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return persons[a] < persons[b];
        });

        vector<int> ans(m);
        int curr = 0;
        auto it = cnt.begin();
        for (int x : indices) {
            while (it != cnt.end() && it->first <= persons[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};





class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.front() < rhs.front();
        };
        
        sort(flowers.begin(), flowers.end(), cmp);
        int n = people.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            ans[i] = getFlowerNum(flowers, people[i]); 
        }
        return ans;
    }
    
    int getFlowerNum(vector<vector<int>>& flowers, int time) {
        int num = 0;
        
        auto cmpFront = [](const auto& lhs, const auto& rhs) { return lhs.front() < rhs.front();};
        auto endIter = upper_bound(flowers.begin(), flowers.end(), vector<int> {time, 0}, cmpFront);
        
        for (auto iter = flowers.begin(); iter != endIter; ++iter) {
            if (iter->back() < time) {
                continue;
            }
            ++num;
        }
        return num;
    }
};