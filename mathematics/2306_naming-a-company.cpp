class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> names;
        for (const string& idea: ideas) {
            names[idea[0]].insert(idea.substr(1, idea.size() - 1));
        }

        auto get_intersect_size = [](const unordered_set<string>& a, const unordered_set<string>& b) -> size_t {
            size_t ans = 0;
            for (const string& s: a) {
                if (b.count(s)) {
                    ++ans;
                }
            }
            return ans;
        };

        long long ans = 0;
        for (auto&& [pre_a, set_a]: names) {
            for (auto&& [pre_b, set_b]: names) {
                if (pre_a == pre_b) {
                    continue;
                }
                int intersect = get_intersect_size(set_a, set_b);
                ans += static_cast<long long>(set_a.size() - intersect) * (set_b.size() - intersect);
            }
        }
        return ans;
    }
};




class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        
        long long ans  = static_cast<long long>(n) * (n - 1);
        const int len = 26;
        vector<int> firstCh(len, 0);
        unordered_set<string> strSet;
        
        sort(ideas.begin(), ideas.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.length() < rhs.length() ? true ? lhs
        }

        for (auto& idea : ideas) {
            int index = idea[0] - 'a';
            ++firstCh[index];
            strSet.insert(idea);
        }
        
        for (auto& idea : ideas) {
            int id = idea[0] - 'a';
            for (int i = 0; i < len; i++) {
                if (firstCh[i] == 0) {
                    continue;
                }
                if (i == id) {
                    ans -= firstCh[i] - 1;
                    continue;
                }
                idea[0] = 'a' + i;
                if (strSet.count(idea)) {
                    ans -= firstCh[i];
                    firstCh[i]++;
                }
            }
        }
        
        return ans;
    }
};