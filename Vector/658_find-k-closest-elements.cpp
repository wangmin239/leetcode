class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool {
            return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b;
        });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};




class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left;
        int len = arr.size();
        int minStartIndex;
        int minDiff = accumulate(arr.begin(), arr.begin() + k, x, 
            [](int x, int y) {return abs(x - y);});



        for (left = 1; left <= len - k; left++) {
            int sum += abs(arr[left + k - 1] - x) - abs(arr[left - 1] - x); 
            if (sum < 0) {
                minDiff += sum;
                minStartIndex = left;
            }
        }

        return vector<int> (arr.begin() + minStartIndex, arr.begin() + minStartIndex + k);
    }
};


