class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto len1 = sentence1.length();
        auto len2 = sentence2.length();
     
        if (len1 == len2) {
            return sentence1 == sentence2;
        }
        
        bool ans;
        if (len1 > len2) {
            ans = isSimilar(sentence1, sentence2);
        } else {
            ans = isSimilar(sentence2, sentence1);
        } 
        
        return ans;
    }
   
    bool isSimilar(const string &str1, const string &str2) {
        auto len1 = str1.length();
        auto len2 = str2.length();
        int left;
 
        for (left = 0; left < len2; left++) {
            if (str1[left] != str2[left]) {
                break;
            }
        }
        /* The str2 is a prefix of the str1 */
        if (left == len2 && str1[left] == ' ') {
            return true;
        }

        int right = len2 - 1;
        int i = len1 - 1;
        do {
            if (str1[i] != str2[right]) {
                break;
            }
            --i;
            --right;
        } while (right >= left);

        /* Check if the str2 is a suffix of the str1 */      
        if (right == -1) {
            return str1[i] == ' ' ? true : false;
        }
        
        /* Check if the str2 is able to be replenished as the str1 */
        return (right + 1 == left) && (str1[i] == str2[right]);
    }
};



class Solution {
public:
    vector<string_view> split(const string & str, char target) {
        vector<string_view> res;
        string_view s(str);
        int pos = 0;
        while (pos < s.size()) {
            while (pos < s.size() && s[pos] == target) {
                pos++;
            }
            int start = pos;
            while (pos < s.size() && s[pos] != target) {
                pos++;
            }
            if (pos > start) {
                res.emplace_back(s.substr(start, pos - start));
            }
        }
        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string_view> words1 = split(sentence1, ' ');
        vector<string_view> words2 = split(sentence2, ' ');
        int i = 0, j = 0;
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            i++;
        }
        while (j < words1.size() - i && j < words2.size() - i && words1[words1.size() - j - 1] == (words2[words2.size() - j - 1])) {
            j++;
        }
        return i + j == min(words1.size(), words2.size());
    }
};
