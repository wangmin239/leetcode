class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int prev = max(arr[0], arr[1]);
        if (k == 1) {
            return prev;
        }
        int consecutive = 1;
        int maxNum = prev;
        int length = arr.size();
        for (int i = 2; i < length; i++) {
            int curr = arr[i];
            if (prev > curr) {
                consecutive++;
                if (consecutive == k) {
                    return prev;
                }
            } else {
                prev = curr;
                consecutive = 1;
            }
            maxNum = max(maxNum, curr);
        }
        return maxNum;
    }
};




class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> que;
        int cnt = 0;
        int firstVal, secondVal;
        int maxVal = *max_element(arr.begin(), arr.end());

        if (maxVal == arr.front()) {
            return maxVal;
        }

        for (int val : arr) {
            que.push(val);
        }
        /* obtain the firstVal value */
        firstVal = que.front();
        que.pop();

        while (cnt != k) {
            secondVal = que.front();           
            que.pop();
            /* compare to the adjacent value */
            if (firstVal > secondVal) {
                ++cnt;
                que.push(secondVal);
            } else {
                cnt = 1;
                que.push(firstVal);
                firstVal = secondVal;
                /* in the case that firstVal value is the bigest digit */
                if (firstVal == maxVal) {
                    return maxVal;
                }
            }
            
        }
        
        return firstVal;
    }
};