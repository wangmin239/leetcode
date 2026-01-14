class Solution {
public:
    vector<int> get(string &word) {
        vector<int> diff(word.size() - 1);
        for (int i = 0; i + 1 < word.size(); i++) {
            diff[i] = word[i + 1] - word[i];
        }
        return diff;
    }

    string oddString(vector<string>& words) {
        auto diff0 = get(words[0]);
        auto diff1 = get(words[1]);
        if (diff0 == diff1) {
            for (int i = 2; i < words.size(); i++) {
                if (diff0 != get(words[i])) {
                    return words[i];
                }
            }
        }
        return diff0 == get(words[2]) ? words[1] : words[0];
    }
};



class Solution {
public:
    string oddString(vector<string>& words) {
      int length = words.front().length();
      vector<int> difference(length - 1, 0);
      
      for (int i = 1; i < length; i++) {
          difference[i - 1] = words[0][i] - words[0][i - 1];
      }
      int cnt = 1;
      int index = 0;
      for (int i = 1; i < static_cast<int>(words.size()); i++) {
        bool match = true;
        for (int j = 1; j < length; j++) {
            if (words[i][j] != words[i][j - 1] + difference[j - 1]) {
                match = false;
                index = i;
                break;
            }
        }
        if (match == true) {
            ++cnt;
        }
        if (index != 0 && cnt > 1) {
            return words[index];
        }
                
      }
      return words.front();
      
    }
};




class Solution {
public:
    string oddString(vector<string>& words) {
      int length = words.front().length();
      vector<int> difference(length - 1, 0);
      
      for (int i = 1; i < length; i++) {
          difference[i - 1] = words[0][i] - words[0][i - 1];
      }
      int cnt = 1;
      int index = 0;
      for (int i = 1; i < static_cast<int>(words.size()); i++) {
        bool match = true;
        for (int j = 1; j < length; j++) {
            if (words[i][j] != words[i][j - 1] + difference[j - 1]) {
                match = false;
                index = i;
                break;
            }
        }
        if (match == true) {
            ++cnt;
        }
      }
      return cnt > 1 ? words[index] : words.front();
      
    }
};