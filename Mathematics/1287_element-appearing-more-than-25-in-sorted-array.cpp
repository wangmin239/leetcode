class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        for (int i = 0; i < n; i += span) {
            auto [iter_l, iter_r] = equal_range(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= span) {
                return arr[i];
            }
        }
        return -1;
    }
};




class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        for (int i = 0; i < n; i += span) {
            auto iter_l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto iter_r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= span) {
                return arr[i];
            }
        }
        return -1;
    }
};




class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cur = arr[0], cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == cur) {
                ++cnt;
                if (cnt * 4 > n) {
                    return cur;
                }
            }
            else {
                cur = arr[i];
                cnt = 1;
            }
        }
        return -1;
    }
};



class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int ans;
        for (int left = 0, right = 0; right < n; right++) {
            while (right < n && arr[left] == arr[right]) {
                right++;
            }
            
            if (right - left > n / 4) {
                ans = arr[left];
                break;
            }
            left = right;
        }
        
        return ans;
    }
};