class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        if(n==0) return t[0];
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        char ch;
        for(int i = 0 ; i < n ; i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        return t[n];

    }
};