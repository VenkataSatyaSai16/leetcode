class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount = 0;
        for(auto &arr : grid){
            for(int i : arr){
                if(i<0) negativeCount++;
            }
        }
        return negativeCount;
    }
};