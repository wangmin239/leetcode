
/* Original Solution 1 */
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> skillKinds;
        unordered_map<int, long long> damageValue;
        long long maxPower = 0;

        for (const int kind : power) {
            ++skillKinds[kind];
        }
        /* Sort each magician's skill value in ascending order */
        int n = skillKinds.size();
        vector<pair<int, int>> skills(n);
        int k = 0;
        for (const auto& kind : skillKinds) {
            skills[k++] = kind;
        }            


        sort(skills.begin(), skills.end());

        for (int i = 0; i < n; i++) {
            int skill = skills[i].first;
            int cnt = skills[i].second;

            damageValue[skill] = 1LL * skill * cnt;

            for (int j = i - 1; j >= 0; j--) {
                int preSkill = skills[j].first;
                /* Find the first magician whose skill value is less than the current magician's */
                if (preSkill <= skill - 3) {
                    damageValue[skill] += damageValue[preSkill];
                    break;
                }
            }

            maxPower = max(maxPower, damageValue[skill]);
            damageValue[skill] = maxPower;
        }

        return maxPower;
    }
};


/* Official Solution 1 */
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> count;
        for (int p : power){
            count[p]++;
        }
        vector<pair<int, int>> vec={{-1e9,0}};
        for (auto& p : count){
            vec.push_back(p);
        }
        int n = vec.size();
        vector<long long> f(n, 0);
        long long mx = 0;
        for (int i = 1, j = 1; i < n; i++) {
            while (j < i && vec[j].first < vec[i].first - 2) {
                mx = max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1LL * vec[i].first * vec[i].second;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++){
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
