class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, char*> chMap;
        char *token = strtok(const_cast<char*>(s.c_str()), " ");

        for (auto ch : pattern) {
            /* the number of the string is less than pattern's length */
            if (token == nullptr) {
                return false;
            }

            /*find the string which is represented by the character */
            if (chMap.count(ch) != 0) {
                if(strcmp(chMap[ch], token) != 0) {
                    return false;
                } 
                token = strtok(nullptr, " "); 
                continue;
            }
            /*the character firstly appears */
            if (chMap.count(ch) == 0 && isMapped(token, chMap) == true) {
                return false;
            } 
            chMap.emplace(ch, token);

            token = strtok(nullptr, " ");   
        }
        return token == nullptr;
    }

    bool isMapped(char *str, unordered_map<char, char*>& chMap) {
        for (auto elem : chMap) {
            if (strcmp(elem.second, str) == 0) {
                return true;
            }
        }
        return false;
    }
};