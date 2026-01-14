class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();  
        unordered_map<int, int> arrSeq;
        vector<int> ansVec(arr);
        int seq = 0;

        sort(ansVec.begin(), ansVec.end());

        for (const int val : ansVec) {
            if (!arrSeq.count(val)) {
                seq++;
            }
            arrSeq[val] = seq;
        }

        for (int i = 0; i < n; i++) {
            ansVec[i] = arrSeq[arr[i]];
        }
        
        return ansVec;
    }
};



class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return arr;
        }
        
        using pii = pair<int, int>;
        unique_ptr<pii*> pArr = make_unique<pii*>(new pii[n]);
        vector<int> ansVec(arr);
        auto p = *pArr.get();
        
        sort(ansVec.begin(), ansVec.end());
        p[0] = make_pair(ansVec[0], 1);
        for (int i = 1, seq = 1; i < n; i++) {
            if (ansVec[i - 1] != ansVec[i]) {
                seq++;
            }
            
            p[i] = make_pair(ansVec[i], seq);
        }

        for (int i = 0; i < n; i++) {
            int val = arr[i];
            for (int j = 0; j < n; j++) {
                if (val == p[j].first) {
                    ansVec[i] = p[j].second;
                    break;
                }
            }
        }
        
        return ansVec;
    }
};