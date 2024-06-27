
class Solution {
public:
    string smallestString(string s) {
        int len = s.length();
        int index = 0;

        /* Find the first character is not equal to 'a' */
        while (index < len && s[index] == 'a') {
             ++index;
        }
        /* Ensure one operation is done */
        if (index == len) {
            s[len - 1] = 'z';
        }

        while (index < len && s[index] != 'a') {
            s[index] = s[index] - 1;
            ++index;
        }

        return s;
    }
};


#include <ranges>
class Solution {
public:
    string smallestString(string s) {
        if (ranges::all_of(s, [](char c) { return c == 'a'; })) 
            s.back() = 'z';
        else for (char& ch : s | views::drop_while([](char c) { return c == 'a'; })
                               | views::take_while([](char c) { return c != 'a'; }))
            ch--;
        return s;
    }
};


class Solution {
public:
    string smallestString(string s) {
        char target = 'a';
        auto it = std::find_if(s.begin(), s.end(), [target](char c) {
            return c != target;
        }); 
        int indexOfFirstNonA = std::distance(s.begin(), it);
        if (indexOfFirstNonA == s.length()) {
            return s.substr(0, s.length() - 1) + 'z';
        }
        size_t indexOfFirstA_AfterFirstNonA = s.find('a', indexOfFirstNonA);
        if (indexOfFirstA_AfterFirstNonA == string::npos) {
            indexOfFirstA_AfterFirstNonA = s.length();
        }
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (indexOfFirstNonA <= i && i < indexOfFirstA_AfterFirstNonA) {
                res.push_back(static_cast<char>(s[i] - 1));
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};


class Solution {
public:
    string smallestString(string s) {
        int len = s.length();
        string ans(s);
        int index = 0;

        /* Find the first character is not equal to 'a' */
        while (index < len && s[index] == 'a') {
             ++index;
        }
        /* Ensure one operation is done */
        if (index == len) {
            ans[len - 1] = 'z';
        }

        while (index < len && s[index] != 'a') {
            ans[index] = s[index] - 1;
            ++index;
        }

        return ans;
    }
};