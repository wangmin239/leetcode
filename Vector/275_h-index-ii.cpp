class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int arr[] = new int [len + 1];
        
        fill(arr, arr + len + 1, 0);
        
        for (auto val : citations) {
            if (val >= n) {
                arr[n]++;
                continue;
            }
            arr[val]++;
        }
        
        int total = 0;
        int i;
        for (i = len; i >= 0; i--){
            total += arr[i];
            if (total >= i){
                return break;
            }
        }
        delete [] arr;
        return i;
    }
};



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        
        for (int i = 0; i < len; i++) {
            if (citations[i] >= len - i) {
                return i;
            } 
        }
        return 0;
    }
};
