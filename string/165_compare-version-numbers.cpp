/* Original Solution 1 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        
        auto getSubVer = [](size_t& pos, string& verStr) {
            string subVer;
            size_t len = verStr.length();
        
            while (pos < len && verStr[pos] != '.') {
                subVer.push_back(verStr[pos++]);
            }
            return subVer;
        };
        
        for (size_t index1 = 0, index2 = 0; index1 < len1 || index2 < len2; index1++, index2++) {
            string verStr1 = getSubVer(index1, version1);
            string verStr2 = getSubVer(index2, version2);
            int ver1 = verStr1.empty() ? 0 : stoi(verStr1);
            int ver2 = verStr2.empty() ? 0 : stoi(verStr2);
            
            if (ver1 != ver2) {
                return ver1 > ver2 ? 1 : -1;
            }   
        }
        return 0;
    }
};




/* Original Solution 2 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto getDotPos = [](const string& verStr) {
            auto pos = verStr.find('.');
            
            if (pos == string::npos) {
                pos = verStr.length();
            }
            
            return pos;
        };
        
        int pos1 = getDotPos(version1);
        int pos2 = getDotPos(version2);
        int ver1 = stoi(version1.substr(0, pos1));
        int ver2 = stoi(version2.substr(0, pos2));
        
        if (ver1 != ver2) {
            return ver1 > ver2 ? 1 : -1;
        }
        
        if (pos1 != version1.length() && pos2 != version2.length()) {
            return compareVersion(version.substr(pos1 + 1), version2.substr(pos2 + 1));
        }
        
        if (pos1 == version1.length() && pos2 != version2.length()) {
            return compareVersion("0", version2.substr(pos2 + 1));
        }

        if (pos1 != version1.length() && pos2 == version2.length()) {
            return compareVersion(version1.substr(pos1 + 1), "0");
        }
        
        return 0;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            long long x = 0;
            for (; i < n && version1[i] != '.'; ++i) {
                x = x * 10 + version1[i] - '0';
            }
            ++i; // 跳过点号
            long long y = 0;
            for (; j < m && version2[j] != '.'; ++j) {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};
