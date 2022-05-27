class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> word1Seq;
        vector<int> word2Seq;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                word1Seq.push_back(i);
                continue;
            } 
            
            if (words[i] == word2) {
                word2Seq.push_back(i);
            }
        }
        
        return getMinDistance(word1Seq, word2Seq);
    }
    
#if 0 
    int getMinDistance(const vector<int>& seq1, const vector<int>& seq2) {
        int minDist = INT_MAX;
        
        for (const auto i : seq1) {
            for (const auto j : seq2) {
                minDist = min(abs(i -j), minDist);
            }
        }
        return minDist;
    }
#endif    
    int getMinDistance(const vector<int>& seq1, const vector<int>& seq2) {
        int minDist = INT_MAX;
        
        for (int i = 0, j = 0; i < seq1.size() && j < seq2.size();) {
            if (seq1[i] > seq2[j]) {
                minDist = min(minDist, seq1[i] - seq2[j]);
                j++;
            } else {
                minDist = min(minDist, seq2[j] - seq1[i]);
                i++;
            }
            
        }
        
        return minDist;
    }

};


class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int length = words.size();
        int ans = length;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < length; i++) {
            string word = words[i];
            if (words[i] == word1) {
                index1 = i;
            } else if (words[i] == word2) {
                index2 = i;
            }
            if (index1 >= 0 && index2 >= 0) {
                ans = min(ans, abs(index1 - index2));
            }
        }
        return ans;
    }
};

