/* Official Solution, Brute-force solving */
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> array1, array2;
        int res = 0;
        int n = arrays.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                array1 = arrays[i];
                array2 = arrays[j];
                res = max(res, abs(array1[0] - array2[array2.size() - 1]));
                res = max(res, abs(array2[0] - array1[array1.size() - 1]));
            }
        }
        return res;
    }
};




/* Official Solution */
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int n = arrays[0].size();
        int min_val = arrays[0][0];
        int max_val = arrays[0][arrays[0].size() - 1];
        for (int i = 1; i < arrays.size(); i++) {
            n = arrays[i].size();
            res = max(res, max(abs(arrays[i][n - 1] - min_val), 
                               abs(max_val - arrays[i][0])));
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i][n - 1]);
        }
        return res;
    }
};




/* Original Solution */
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>> decrPq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> incrPq {greater<pair<int, int>>()};
        int m = arrays.size();
        
        for (int i = 0; i < m; i++) {
            decrPq.push({arrays[i].back(), i});
            incrPq.push({arrays[i].front(), i});
        }
        
        auto maxNode = decrPq.top();
        auto minNode = incrPq.top();
        
        if (maxNode.second != minNode.second) {
            return maxNode.first - minNode.first;
        }
        
        decrPq.pop();
        incrPq.pop();
        
        auto secondMaxNode = decrPq.top();
        auto secondMinNode = incrPq.top();
        
        return max(maxNode.first - secondMinNode.first, secondMaxNode.first - minNode.first);
    }
};

/* Optimize Original Solution */
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> decrVec(2);
        vector<pair<int, int>> incrVec(2);
        int m = arrays.size();
        
        /* Sort the front two elements */
        for (int i = 0; i < 2; i++) {
            decrVec[i] = make_pair(arrays[i].back(), i);
            incrVec[i] = make_pair(arrays[i].front(), i);
        }
        
        sort(decrVec.begin(), decrVec.end(), greater<pair<int, int>>());
        sort(incrVec.begin(), incrVec.end(), less<pair<int, int>>());
        
        /* Compare the new inserted element */
        for (int i = 2; i < m; i++) {
           if (arrays[i].back() >= decrVec.front().first) {
               decrVec.back() = decrVec.front();
               decrVec.front() = make_pair(arrays[i].back(), i);
           } else if (arrays[i].back() >= decrVec.back().first) {
               decrVec.back() = make_pair(arrays[i].back(), i);
           }
           
           if (arrays[i].front() <= incrVec.front().first) {
               incrVec.back() = incrVec.front();
               incrVec.front() = make_pair(arrays[i].front(), i);
           } else if (arrays[i].front() <= incrVec.back().first) {
               incrVec.back() = make_pair(arrays[i].front(), i);
           }
        }
        
        auto maxNode = decrVec.front();
        auto minNode = incrVec.front();
        
        if (maxNode.second != minNode.second) {
            return maxNode.first - minNode.first;
        }
        
        auto secondMaxNode = decrVec.back();
        auto secondMinNode = incrVec.back();
        
        return max(maxNode.first - secondMinNode.first, secondMaxNode.first - minNode.first);
    }
};