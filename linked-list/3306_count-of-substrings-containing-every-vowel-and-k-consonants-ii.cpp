class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        
        vector<int> prefix_consonant(n + 1, 0);
        for(int i = 0; i < n; ++i){
            if(!isVowel(word[i])){
                prefix_consonant[i+1] = prefix_consonant[i] + 1;
            }
            else{
                prefix_consonant[i+1] = prefix_consonant[i];
            }
        }
        
        vector<vector<int>> list_of_prefix_consonants(n + 2, vector<int>());
        for(int i = 0; i <= n; ++i){
            list_of_prefix_consonants[prefix_consonant[i]].push_back(i);
        }
        
        int last_a = -1, last_e = -1, last_i = -1, last_o = -1, last_u = -1;
        
        long long answer = 0;
        
        for(int j = 0; j < n; ++j){
            if(word[j] == 'a') last_a = j;
            else if(word[j] == 'e') last_e = j;
            else if(word[j] == 'i') last_i = j;
            else if(word[j] == 'o') last_o = j;
            else if(word[j] == 'u') last_u = j;
            
            int min_start = min({last_a, last_e, last_i, last_o, last_u});
            
            if(min_start == -1){
                continue;
            }
            
            int current_consonants = prefix_consonant[j+1];
            int target = current_consonants - k;
            
            if(target < 0){
                continue;
            }
            
            if(target > n){
                continue;
            }
            
            const vector<int> &indices = list_of_prefix_consonants[target];
            int cnt = upper_bound(indices.begin(), indices.end(), min_start) - indices.begin();
            
            answer += cnt;
        }
        
        return answer;
    }
    
private:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto count = [&](int m) -> long long {
            int n = word.size(), consonants = 0;
            long long res = 0;
            map<char, int> occur;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && (consonants < m || occur.size() < vowels.size())) {
                    if (vowels.count(word[j])) {
                        occur[word[j]]++;
                    } else {
                        consonants++;
                    }
                    j++;
                }
                if (consonants >= m && occur.size() == vowels.size()) {
                    res += n - j + 1;
                }
                if (vowels.count(word[i])) {
                    occur[word[i]]--;
                    if (occur[word[i]] == 0) {
                        occur.erase(word[i]);
                    }
                } else {
                    consonants--;
                }
            }
            return res;
        };
        return count(k) - count(k + 1);
    }
};
