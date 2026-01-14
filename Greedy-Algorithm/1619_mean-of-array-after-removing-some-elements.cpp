class Solution {
public:
    double trimMean(vector<int>& arr) {
        int len = arr.size();
        int left, right;
        
        sort(arr.begin(), arr.end());
        
        left = len / 20;
        right = len - len / 20;
        
        double sum = 0;
        int cnt = len - len / 10;
        
        while (left < right) {
            sum += static_cast<double>(arr[left++]) / cnt;
        }
        
        return sum;
    }
};

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int partialSum = accumulate(arr.begin() + n / 20, arr.begin() + (19 * n / 20), 0);
        return partialSum / (n * 0.9);
    }
};



class Solution {
public:
    double trimMean(vector<int>& arr) {
        auto dis = arr.size() / 20;
        nth_element(arr.begin(),  arr.begin()  + dis, arr.end());
        nth_element(arr.rbegin(), arr.rbegin() + dis, arr.rend(), greater{});
        return accumulate(arr.begin() + dis, arr.end() - dis, 0.0) / (arr.size() * 0.9);
    }
};