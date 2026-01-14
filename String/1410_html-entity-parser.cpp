class Solution {
public:
    using EntityChar = pair <string, char>;

    vector <EntityChar> entityList;

    string entityParser(string text) {
        entityList = vector({
            (EntityChar){"&quot;", '"'},
            (EntityChar){"&apos;", '\''},
            (EntityChar){"&amp;", '&'},
            (EntityChar){"&gt;", '>'},
            (EntityChar){"&lt;", '<'},
            (EntityChar){"&frasl;", '/'}
        });

        string r = "";
        for (int pos = 0; pos < text.size(); ) {
            bool isEntity = false;
            if (text[pos] == '&') {
                for (const auto &[e, c]: entityList) {
                    if (text.substr(pos, e.size()) == e) {
                        r.push_back(c);
                        pos += e.size();
                        isEntity = true;
                        break;
                    }
                }
            }
            if (!isEntity) {
                r.push_back(text[pos++]);
                continue;
            }
        }
        return r;
    }
};



class Solution {
public:
    string entityParser(string text) {
        string ans;
        auto parser = [](string& word) -> string {
            const int num = 6;
            string pattern[num] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
            string replace[num] = {"\"", "'", "&", ">", "<", "/"}; 
            
            for (int i = 0; i < num; i++) {
                auto pos = word.find(pattern[i]);
                if (pos != string::npos) {
                    return word.substr(0, pos) + replace[i];
                }
            }
            return word;
        };
        
        int len = text.length();
        int i = 0;
        for (int j = i; j < len; j++, i = j) {
            if (text[j] != '&') {
                ans.push_back(text[j]);
            } else {
                i = j;
                while (j < len && text[j] != ';') {
                    j++;
                }
                string word(text.substr(i, j - i + 1));
                ans.append(parser(word));
            }
        }
            
        ans += text.substr(i);
        return ans;
    }
};