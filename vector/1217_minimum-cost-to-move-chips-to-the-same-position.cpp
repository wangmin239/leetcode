class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
       int evenSum = 0;
       int oddSum = 0;
       
       for (size_type i = 0; i < position.size(); i++) {
           if (position[i] & 0x1) {
               ++oddSum;
               continue;
           }
           ++evenSum;
       }
       
       return min(evenSum, oddSum);
       
    }
};