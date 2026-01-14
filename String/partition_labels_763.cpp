class Solution {
public:
    vector<int> partitionLabels(string S) {
		int positionHash[26] = {0};
		for (int i = 0; i < S.length(); i++) {
			positionHash[S[i] - 'a'] = i;
		}
		
		int begin = 0;
		int end = 0;
		vector<int> res;
		for (int i = 0; i < S.length(); i++) {
			end = max(end, positionHash[S[i] - 'a']);
			if (i == end) {
				res.emplace_back(end - begin + 1);
				begin = end + 1;
			}
		}
		return res;
    }
}; 