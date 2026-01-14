class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n = student_id.size();
        vector<pair<int, int>> points(n);
        unordered_map<string, int> pointsMap;
        const int addPoint = 3;
        const int subPoint = -1;
        
        for (const auto& posStr : positive_feedback) {
            pointsMap[posStr] = addPoint;
        }
        
        for (const auto& negStr : negative_feedback) {
            pointsMap[negStr] = subPoint;
        }

        for (int i = 0; i < n; i++) {
            int id = student_id[i];
            int point = getPoints(report[i], pointsMap);
            points[i] = make_pair(id, point);
        }

        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.second == rhs.second ? lhs.first < rhs.first :lhs.second > rhs.second;
        };

        sort(points.begin(), points.end(), cmp);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = points[i].first;
        }
        return ans;

    }

    int getPoints(const string& reportStr, unordered_map<string, int>& pointsMap) {
        int points = 0;

        auto calcu = [&](const string& word) {
            if (pointsMap.count(word)) {
                points  += pointsMap[word];
            }
        };
        /* abstract one word to match the positive table or negative table */
        int j;
        for (int i = 0; i < reportStr.length(); i++) {
            for (j = i; i < reportStr.length(); i++) {
                if (reportStr[i] != ' ') {
                    continue;
                }

                calcu(reportStr.substr(j, i - j));
                break;
            }
        }
        /* add the last word */
        calcu(reportStr.substr(j));
        return points;
    }
};


class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n = student_id.size();
        vector<pair<int, int>> points(n);
        unordered_set<string> posSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negSet(negative_feedback.begin(), negative_feedback.end());

        for (int i = 0; i < n; i++) {
            int id = student_id[i];
            int point = getPoints(report[i], posSet, negSet);
            points[i] = make_pair(id, point);
        }

        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.second == rhs.second ? lhs.first < rhs.first :lhs.second > rhs.second;
        };

        sort(points.begin(), points.end(), cmp);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = points[i].first;
        }
        return ans;

    }

    int getPoints(const string& reportStr, unordered_set<string>& posSet, unordered_set<string>& negSet) {
        int total = 0;
        auto calcu = [&](const string& word) {
            if (posSet.count(word)) {
                total += 3;
            }
            if (negSet.count(word)) {
                total -= 1;
            }
        };
        /* abstract one word to match the positive table or negative table */
        int j;
        for (int i = 0; i < reportStr.length(); i++) {
            for (j = i; i < reportStr.length(); i++) {
                if (reportStr[i] != ' ') {
                    continue;
                }

                calcu(reportStr.substr(j, i - j));
                break;
            }
        }
        calcu(reportStr.substr(j));
        return total;
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set pos(positive_feedback.begin(), positive_feedback.end())
                    , neg(negative_feedback.begin(), negative_feedback.end());
        vector score(student_id.size(), 0l);
        ranges::transform(report, student_id, score.begin()
          , [](long sc, unsigned id) { return -(sc << 32 | id); }
          , [&](auto&& s) { istringstream ss(s);
                return accumulate(istream_iterator<string>(ss), {}, 0l
                            , [&](auto a, auto&& s) { return a + pos.count(s) * 3 - neg.count(s); }); }
          , negate{});  // 为规避C4146，在转换成无符号前取负
        ranges::partial_sort(score, score.begin() + k);
        return { score.begin(), score.begin() + k }; // 整型窄缩，截断出低32位
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<std::string, int> words;
        for (const auto& word : positive_feedback) {
            words[word] = 3;
        }
        for (const auto& word : negative_feedback) {
            words[word] = -1;
        }
        vector<vector<int>> A;
        for (int i = 0; i < report.size(); i++) {
            stringstream ss; //stream根据空格分词
            string w;
            int score = 0;
            ss << report[i];
            while (ss >> w) {
                if (words.count(w)) {
                    score += words[w];
                }
            }
            A.push_back({-score, student_id[i]});
        }
        sort(A.begin(), A.end());
        vector<int> top_k;
        for (int i = 0; i < k; i++) {
            top_k.push_back(A[i][1]);
        }
        return top_k;
    }
};
