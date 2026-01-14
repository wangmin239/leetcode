/* Original Solution 1 */
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> fruitKinds;
        const int kinds = 2;
        int ans = 0;
        int left, right;
        auto checkKind = [](unordered_map<int, int>& fruitKinds) {
            int kinds = 0;
            for (auto [_, cnt] : fruitKinds) {
                if (cnt != 0) {
                    ++kinds;
                }
            }
            
            return kinds;
        };
        
        for (left = 0, right = 0; right < n; right++) {
            int kindId = fruits[right];
            
            ++fruitKinds[kindId];
            /* The fruits kinds in basket is greater than 2. */
            if (checkKind(fruitKinds) > kinds) {
                ans = max(ans, right - left);
            }
            
            /* move the left pointer to reduce the fruit kinds */
            while (checkKind(fruitKinds) > kinds) {
                int preKindId = fruits[left++];
                
                --fruitKinds[preKindId];
            }
        }
        
        ans = max(ans, right - left);
        
        return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> fruitKinds;
        const int kinds = 2;
        int ans = 0;
        int left, right;
        
        for (left = 0, right = 0; right < n; right++) {
            int kindId = fruits[right];
            
            ++fruitKinds[kindId];
            /* The fruits kinds in basket is greater than 2. */
            if (fruitKinds.size() > kinds) {
                ans = max(ans, right - left);
            }
            
            /* move the left pointer to reduce the fruit kinds */
            while (fruitKinds.size() > kinds) {
                int preKindId = fruits[left++];
                
                if (--fruitKinds[preKindId] == 0) {
                    fruitKinds.erase(preKindId);
                }
            }
        }
        
        ans = max(ans, right - left);
        
        return ans;
    }
};


/* Official solution 1 */
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;

        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                --it->second;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
