class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        auto len = arr.size();
        int *arrCnt = new int [len + 1];
        
        fill(arrCnt, arrCnt + len + 1, 0);
        for (int i = 0; i < len; i++) {
            int index = min(arr[i], len);
            arrCnt[index]++;
        }

        int maxElem = 0;
        
        for (int i = 1; i <= len; i++) {
            maxElem = min(maxElem + arrCnt[i], i);
        }
        delete [] arrCnt;
        return maxElem;     
    }
};

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[n-1];
    }
};



