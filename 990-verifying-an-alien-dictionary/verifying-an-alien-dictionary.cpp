class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for(int i = 0 ; i < order.length() ; i++){
            rank[order[i]-'a'] = i;
        }
        for(int i = 0 ; i < words.size() - 1 ; i++){
            int j = 0 ;
            while(j<words[i].size() && j<words[i+1].size()){
                if(rank[words[i][j]-'a'] > rank[words[i+1][j]-'a']) return false;
                if(rank[words[i][j]-'a'] < rank[words[i+1][j]-'a']) break;
                j++;
            }
            if(j==words[i+1].size() && j < words[i].size()){
                return false;
            }
        }
        return true;
    }
};