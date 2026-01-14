class Solution {
public:
    bool isCircularSentence(string sentence) {
        int len = sentence.length();
        
        if (sentence.front() != sentence.back()) {
            return false;
        }

        for (int i = 0; i < len; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.back() != sentence.front()) {
            return false;
        }
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1]) {
                return false;
            } 
        }
        return true;
    }
};
