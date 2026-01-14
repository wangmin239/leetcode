class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = INT_MIN;
        
        for (string::size_type pos = 0; pos < sequence.length(); ){
            int cnt = 0;
            string tmp(word);
            while (sequence.find(tmp, pos) != string::npos) {
                tmp.append(word);
                cnt++;
            }
            ++pos;

            k = max(k, cnt);
        }
       return k;
    }
};


class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }

        vector<int> f(n);
        for (int i = m - 1; i < n; ++i) {
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if (sequence[i - m + j + 1] != word[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;
            }
        }
        
        return *max_element(f.begin(), f.end());
    }
};

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }

        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && word[j + 1] != word[i]) {
                j = fail[j];
            }
            if (word[j + 1] == word[i]) {
                fail[i] = j + 1;
            }
        }

        vector<int> f(n);
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && word[j + 1] != sequence[i]) {
                j = fail[j];
            }
            if (word[j + 1] == sequence[i]) {
                ++j;
                if (j == m - 1) {
                    f[i] = (i >= m ? f[i - m] : 0) + 1;
                    j = fail[j];
                }
            }
        }

        return *max_element(f.begin(), f.end());
    }
};




class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int k = 0;
        
        auto pos = sequence.find(word);
        
        if (pos == string::npos) {
            return k;
        }
        ++k;
        pos += word.length();
        while (pos < sequence.length()) {
            string::size_type i = 0;
            while (i < word.length() && pos < sequence.length()) {
                if (sequence[pos] == word[i]) {
                    ++pos;
                    ++i;
                } else {
                    return k;
                }
            }
            
            if (i == word.length()) {
                ++k;
            }
        }
        return k;
    }
};