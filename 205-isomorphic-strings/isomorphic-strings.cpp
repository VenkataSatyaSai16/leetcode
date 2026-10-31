class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> from_to , to_from ;
        for(int i = 0 ; i < n ; i++){
            // if(s[i]==t[i]){
            //     from_to[s[i]] = t[i];
            //     to_from[t[i]] = s[i];
            // }else 
            if(from_to.find(s[i])==from_to.end() && to_from.find(t[i])==to_from.end() ){
                from_to[s[i]] = t[i];
                to_from[t[i]] = s[i];
            } else if((from_to.find(s[i])!=from_to.end() && from_to[s[i]]!=t[i]) || (to_from.find(t[i])!=to_from.end() && to_from[t[i]]!=s[i])){
                return false;
            } else{
                continue;
            }
        }
        return true;
    }
};