class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0;
        vector<int> points;
        for (auto &op : ops) {
            int n = points.size();
            switch (op[0]) {
                case '+':
                    ret += points[n - 1] + points[n - 2];
                    points.push_back(points[n - 1] + points[n - 2]);
                    break;
                case 'D':
                    ret += 2 * points[n - 1];
                    points.push_back(2 * points[n - 1]);
                    break;
                case 'C':
                    ret -= points[n - 1];
                    points.pop_back();
                    break;
                default:
                    ret += stoi(op);
                    points.push_back(stoi(op));
                    break;
            }
        }
        return ret;
    }
};





class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> st;
        
        for (const string& op : operations) {
            if (op == "C") {
                st.pop();
                continue;
            }
            
            if (op == "D") {
                int val = st.top();
                st.push(val << 1);
                continue;
            }
            
            if (op == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
                continue;
            }
            
            int val = stoi(op);
            st.push(val);
        }
        
        while (st.empty() == false) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};