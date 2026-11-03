class Solution {
public:
    bool validate(vector<int> &charCount1 , vector<int> &charCount2){
        for(int i = 0 ; i < 26 ; i++){
            if(charCount1[i]>charCount2[i]) return false;
        }
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> charCount(26,0);
        for(char ch : licensePlate){
            char c = tolower(ch);
            if(c>='a'&&c<='z'){
                charCount[c-'a']++;
            }
        }
        string result = "";
        for(string str : words){
            vector<int> charCount2(26,0);
            for(char ch:str){
                charCount2[ch-'a']++;
            }
            if(validate(charCount,charCount2)){
                if(result==""){
                    result = str;
                }
                if(str.size()<result.size()){
                    result = str;
                }
            }
        }
        return result;
    }
};