class Solution {
public:
    string finalString(string s) {
        deque<char> q;
        bool head = false;
        for (char ch: s) {
            if (ch != 'i') {
                if (head) {
                    q.push_front(ch);
                }
                else {
                    q.push_back(ch);
                }
            }
            else {
                head = !head;
            }
        }
        string ans = (head ? string{q.rbegin(), q.rend()} : string{q.begin(), q.end()});
        return ans;
    }
};



class Solution {
public:
    string finalString(string s) {
        string ans;
        
        for (char ch : s) {
            if (ch != 'i') {
                ans.push_back(ch);
            } else {
                reverse(ans.begin(), ans.end());
            }
        }
        
        return ans;
    }
};