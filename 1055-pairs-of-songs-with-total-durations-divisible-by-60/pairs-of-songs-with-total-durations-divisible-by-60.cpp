class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();

        unordered_map<int,int> mp; //<remainder,frequency>
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int x = time[i] % 60;

            int y = (60 - (x-60)) % 60;

            if(mp.find(y)!=mp.end()){
                count += mp[y];
            }
            mp[x]++;
        }
        return count;
    }
};