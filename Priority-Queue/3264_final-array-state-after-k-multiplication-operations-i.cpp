class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            auto iter = min_element(nums.begin(), nums.end());
            *iter *= multiplier;
        }
        return nums;
    }
};



class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (size_t i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        
        while (k--) {
            auto element = pq.top();
            int id = element.second;
            
            pq.pop();
            nums[id] *= multiplier;
            pq.emplace(nums[id], id);
        }
        
        return nums;
    }
};


class Solution {
public:
    long long quickMul(long long x, long long y, long long m) {
        long long res = 1;
        while (y) {
            if (y & 1) {
                res = (res * x) % m;
            }
            y >>= 1;
            x = (x * x) % m;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        long long n = nums.size(), m = 1e9 + 7;
        long long mx = *max_element(nums.begin(), nums.end());
        vector<pair<long long, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        make_heap(v.begin(), v.end(), greater<>());
        for (; v[0].first < mx && k; k--) {
            pop_heap(v.begin(), v.end(), greater<>());
            v.back().first *= multiplier;
            push_heap(v.begin(), v.end(), greater<>());
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int t = k / n + (i < k % n);
            nums[v[i].second] = ((v[i].first % m) * quickMul(multiplier, t, m)) % m;
        }
        return nums;
    }
};
