class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int denominator = 2; denominator <= n; ++denominator) {
            for (int numerator = 1; numerator < denominator; ++numerator) {
                if (__gcd(numerator, denominator) == 1) {
                    ans.emplace_back(to_string(numerator) + "/" + to_string(denominator));
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        using pii = pair<int, int>;
        auto keyHash = [](const pii& k)  {
            return hash<int>()(k.first ^ (k.second << 1));
        };
        auto keyEqual = [] (const pii& lhs, const pii& rhs)  {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        };
        
        unordered_map<pii, int, decltype(keyHash), decltype(keyEqual)> duplicatedMap(0, keyHash, keyEqual);
        vector<string> ans;
        
        for (int denominator = 2; denominator <= n; denominator++) {
            for (int numerator = 1; numerator < denominator; numerator++) {
                if (duplicatedMap.count({numerator, denominator}) > 0) {
                    continue;
                }
                
                ans.push_back({to_string(numerator) + "/" + to_string(denominator)});
   
                int multiple = n / denominator;
                for (int i = 2; i <= multiple; i++) {
                    duplicatedMap.emplace(pair {numerator * i, denominator * i}, 0);
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        using pii = pair<int, int>;
        map<pii, int> duplicatedMap;
        vector<string> ans;
        
        for (int denominator = 2; denominator <= n; denominator++) {
            for (int numerator = 1; numerator < denominator; numerator++) {
                if (duplicatedMap.count({numerator, denominator}) > 0) {
                    continue;
                }
                
                ans.push_back({to_string(numerator) + "/" + to_string(denominator)});
   
                int multiple = n / denominator;
                for (int i = 2; i <= multiple; i++) {
                    duplicatedMap.emplace(pair {numerator * i, denominator * i}, 0);
                }
            }
        }

        return ans;
    }
};