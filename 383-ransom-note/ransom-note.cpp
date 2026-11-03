class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charCount(26,0);
        for(char ch : magazine){
            charCount[ch-'a']++;
        }
        vector<int> charCount2(26,0);
        for(char ch:ransomNote){
            charCount2[ch-'a']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(charCount2[i]>charCount[i]) return false;
        }
        return true;
    }
};