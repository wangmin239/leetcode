class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int l = 0, r = 0;   // 单词左右边界（左闭右开）
        title.push_back(' ');   // 避免处理末尾的边界条件
        while (r < n) {
            while (title[r] != ' ') {
                ++r;
            }
            // 对于每个单词按要求处理
            if (r - l > 2) {
                title[l] = toupper(title[l]);
                ++l;
            }
            while (l < r) {
                title[l] = tolower(title[l]);
                ++l;
            }
            l = r + 1;
            ++r;
        }
        title.pop_back();
        return title;
    }
};



class Solution {
public:
    string capitalizeTitle(string title) {
        int len = title.length();
        string ans(len, 0);
        

        for (int i = 0; i < len; i++) {
            int start = i;
            
            while (i < len && title[i] != ' ') {
                ++i;
            }
            
            /* get the index of the last character */
            int end = i - 1;
            
            /* check if the lenght of the word is less than 2. */
            if (end - start > 1) {
                ans[start] = toupper(title[start]);
                ++start;
            }

            while (start <= end) {
                ans[start] = tolower(title[start]);
                ++start;
            }
            
            /* append a bank to the word. */
            if (title[i] == ' ') {
                ans[start] = title[i];
            }
        }
        return ans;
    }
};
