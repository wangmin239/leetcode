class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> xIndex;
        
        
        /* filt the value isn't equal to x, store the index of every x */
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                xIndex.push_back(i);
            }
        }
        
        int len = queries.size();
        vector<int> results(len, -1);
        
        /* X doesn't exist in nums */
        if (xIndex.empty() == true) {
            return results;
        }
        
        /* check if the index is bigger than the size of the vector storaging x */
        int xLen = xIndex.size();
        for (int i = 0; i < len; i++) {
            if (queries[i] > xLen) {
                continue;
            }
            
            results[i] = xIndex[queries[i] - 1];
        }
        
        return results;
    }
};


#include <ranges>
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        auto v = nums | views::enumerate 
                      | views::filter([x](auto p) { return get<1>(p) == x; }) 
                      | views::keys | ranges::to<vector<int>>();
        return queries | views::transform([&v](int i) { return v.size() < i ? -1 : v[i - 1]; })
                       | ranges::to<vector>();
    }
};