class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> strMap;
        
        for (const auto& str : words) {
            int chBits = 0;
            for (const auto ch : str) {
                chBits |= 1 << (ch - 'a');
            }

            strMap[chBits] = max(strMap[chBits], static_cast<int>(str.length()));

        }
        
        int maxValue = 0;
        for (auto iter = strMap.begin(); iter != strMap.end(); ++iter) {
            for (auto postIter = iter; postIter != strMap.end(); ++postIter) {
                /* skip the first element */
                if (postIter == iter) {
                    continue;
                }
                /* The two string don't have one or more common characters. */
                if ((iter->first & postIter->first) == 0) {
                    maxValue = max (maxValue, iter->second * postIter->second);
                }
            }
        }
        
        return maxValue;
        
    }
};
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};


class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> map;
        int length = words.size();
        for (int i = 0; i < length; i++) {
            int mask = 0;
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                mask |= 1 << (word[j] - 'a');
            }
            if(map.count(mask)) {
                if (wordLength > map[mask]) {
                    map[mask] = wordLength;
                }
            } else {
                map[mask] = wordLength;
            }
            
        }
        int maxProd = 0;
        for (auto [mask1, _] : map) {
            int wordLength1 = map[mask1];
            for (auto [mask2, _] : map) {
                if ((mask1 & mask2) == 0) {
                    int wordLength2 = map[mask2];
                    maxProd = max(maxProd, wordLength1 * wordLength2);
                }
            }
        }
        return maxProd;
    }
};
