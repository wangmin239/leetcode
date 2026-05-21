/* Original Solution 1 */
class Trie {
public:
    shared_ptr<Trie> next[10];
};

void addNum(int num,  shared_ptr<Trie> root) {
    stack<int> st;
    const int decimal = 10;

    while (num) {
        st.push(num % decimal);
        num /= decimal;
    }

    while (st.empty() == false) {
        int digit = st.top();

        st.pop();
        if (root->next[digit] == nullptr) {
            root->next[digit] = make_shared<Trie>();
        }
        root = root->next[digit];
    }
}


int getPreLen(int num, shared_ptr<Trie> root) {
    stack<int> st;
    const int decimal = 10;
    int len = 0;

    while (num) {
        st.push(num % decimal);
        num /= decimal;
    }

    while (st.empty() == false) {
        int digit = st.top();
        st.pop();

        if (root->next[digit] == nullptr) {
            break;
        }
        root = root->next[digit];
        ++len;
    }
    return len;
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        shared_ptr<Trie> root(new Trie);
        int len = 0;


        for (int num : arr1) {
            addNum(num, root);
        }

        for (int num : arr2) {
            len = max(len, getPreLen(num, root));
        }
        return len;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> seen;
        for (int num: arr1) {
            while (num > 0) {
                seen.insert(num);
                num /= 10;
            }
        }

        int best = 0;
        for (int num: arr2) {
            while (num > 0) {
                if (seen.count(num)) {
                    best = max(best, num);
                }
                num /= 10;
            }
        }

        return best == 0 ? 0 : to_string(best).size();
    }
};
