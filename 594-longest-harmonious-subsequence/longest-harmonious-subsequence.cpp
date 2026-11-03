class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;

        vector<pair<int,int>> vect(mp.begin(),mp.end());

        sort(vect.begin(),vect.end());
        int maxH = 0;
        for(int i = 1 ; i < vect.size();i++){
            if(vect[i].first - vect[i-1].first <= 1){
                maxH = max(maxH,vect[i].second+vect[i-1].second);
            }
        }
        return maxH;
    }
};