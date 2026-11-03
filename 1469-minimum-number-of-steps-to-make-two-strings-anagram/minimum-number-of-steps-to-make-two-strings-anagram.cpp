class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> charCount1(26,0) , charCount2(26,0);

        for(char ch : s){
            charCount1[ch-'a']++;
        }
        for(char ch : t){
            charCount2[ch-'a']++;
        }
        int count = 0;

        for(int i = 0 ; i < 26 ; i++){
            count+=abs(charCount1[i]-charCount2[i]);
        }
        return count/2;
    }
};