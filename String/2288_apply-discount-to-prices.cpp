class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream sin(sentence), sout;
        sout << fixed << setprecision(2);

        vector<string> words;
        string word;
        while (sin >> word) {
            if (word[0] == '$' && word.size() > 1 && all_of(word.begin() + 1, word.end(), ::isdigit)) {
                double price = stoll(word.substr(1, word.size() - 1)) * (1.0 - discount / 100.0);
                sout << '$' << price;
            }
            else {
                sout << word;
            }
            sout << " ";
        }
        string ans = sout.str();
        ans.pop_back();
        return ans;
    }
};




class Solution {
public:
    string discountPrices(string sentence, int discount) {
       int len = sentence.length();
       string ans;

       for (int i = 0; i < len; i++) {
           int j = i;
           /* Get a word by split the sentence by a bank */
            while (i < len && sentence[i] != ' ') {
                ++i;
            }

            string word(sentence.substr(j, i - j + 1));

            if (isValidPrice(word) == false) {
                ans.append(word);
            }

            ans.push_back('$');  
            ans += convertFrag(word, discount);

            if (i != len) {
                ans.push_back(' ');
            }
       }

       return ans;
    }

    string convertFrag(const string& str, const int discount) {
        double price = stod(str.substr(1));
        stringstream ss;

        /* Calculate the discount */
        price *= 1  -  0.01 * discount;
        ss << fixed << setprecision(2) << price;

        return ss.str();
    }

    bool isValidPrice(const string& word) {
        if (word.front() != '$') {
            return false;
        }      

        size_t i;
        for (i = 1; i < word.length(); i++) {
            if (isdigit(word[i]) == false) {
                break;
            }
        }

        /* The word contains continuous digits, and the last character is
         * a bank or a digit.
         */
        return i > 1 && (i == word.length() || word[i] == ' ');
    }
};