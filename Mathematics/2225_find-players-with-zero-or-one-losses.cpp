class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> freq;
        for (const auto& match: matches) {
            int winner = match[0], loser = match[1];
            if (!freq.count(winner)) {
                freq[winner] = 0;
            }
            ++freq[loser];
        }

        vector<vector<int>> ans(2);
        for (const auto& [key, value]: freq) {
            if (value < 2) {
                ans[value].push_back(key);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};




class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loseCnt;
        
        /* statistic the rounds of a player lost matches. */
        for (const auto& match : matches) {
            ++loseCnt[match.back()];
            if (loseCnt.count(match.front()) == 0) {
                loseCnt[match.front()] = 0;
            }
        }

        const int winnerOrLostOne = 2;
        vector<vector<int>> answer(winnerOrLostOne);
        for (auto [id, loseRounds] : loseCnt) {
            /* in the case that a player have not lost any matches. */
            if (loseRounds == 0) {
                answer.front().push_back(id);
            }
            
            if (loseRounds == 1) {
                answer.back().push_back(id);
            }
        }
        /* sort the result  in increasing order. */
        sort(answer.front().begin(), answer.front().end());
        sort(answer.back().begin(), answer.back().end());
        return answer;
    }
};