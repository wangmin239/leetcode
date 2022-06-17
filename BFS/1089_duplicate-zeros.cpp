class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int top = 0;
        int i = -1;
        while (top < n) {
            i++;
            if (arr[i] != 0) {
                top++;
            } else {
                top += 2;
            }
        }
        int j = n - 1;
        if (top == n + 1) {
            arr[j] = 0;
            j--;
            i--;
        } 
        while (j >= 0) {
            arr[j] = arr[i];
            j--;
            if (!arr[i]) {
                arr[j] = arr[i];
                j--;
            } 
            i--;
        }
    }
};



class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        dfs(0, arr);
    }
    
    void dfs(int index, vector<int>& arr) {
        if (index >= arr.size() - 1) {
            return;
        }
        
        if (arr[index] == 0) {
            for (int j = arr.size() - 2; j > index; j--) {
                arr[j + 1] = arr[j];
            }
            arr[++index] = 0;
        }
        
        dfs(index + 1, arr);
    }
            
};


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        
        for (int i = 0; i < len; i++) {
            if (arr[i] != 0) {
                continue;
            }
            
            for (int j = len - 2; j > i; j--) {
                arr[j + 1] = arr[j];
            }

            if (++i < len) {
                arr[i] = 0;
            }

        }
        return;
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) {
                for (int j = len - 2; j > i; j--) {
                    arr[j + 1] = arr[j];
                }
                if (++i < len) {
                    arr[i] = 0;
                }
            }
        }
        return;
    }
};