class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        int res = 0;
        double sum = accumulate(nums.begin(), nums.end(), 0.0), sum2 = 0.0;
        while (sum2 < sum / 2) {
            double x = pq.top();
            pq.pop();
            sum2 += x / 2;
            pq.push(x / 2);
            res++;
        }
        return res;
    }
};



class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<float> pq;
        long long sum = 0;
        
        for (int val : nums) {
            sum += val;
            pq.emplace(val);
        }
        
        int steps = 0;
        double half = static_cast<double>(sum) / 2;
        
        while (half > 0.0) {
            double val = pq.top();
            pq.pop();
            val /= 2;
            half -= val;
            pq.push(val);
            ++steps;   
        }
        return steps;
    }
};