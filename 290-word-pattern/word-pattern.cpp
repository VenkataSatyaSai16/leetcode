class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> pm;
        int i = 0 , n = s.size();
        for(char ch : pattern){
            if(i>=n) return false;
            string str;
            
            while(i<n && s[i]!=' '){
                str+=s[i++];
            }
            
            if(mp.find(ch)==mp.end() && pm.find(str)==pm.end()){
                mp[ch] = str;
                pm[str] = ch;
            } else if((mp.find(ch)!=mp.end() && mp[ch]!=str) || (pm.find(str)!=pm.end() && pm[str]!=ch)){
                return false;
            }
            i++;
        }
        return i>=n;
    }
};