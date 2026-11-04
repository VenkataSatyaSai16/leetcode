class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        vector<int> charcount1(26, 0);
        for (char ch : word1) {
            charcount1[ch - 'a']++;
        }
        vector<int> charcount2(26, 0);
        for (char ch : word2) {
            charcount2[ch - 'a']++;
        }
        
        for(int i = 0 ; i < 26 ; i++){
            if((charcount1[i]==0 && charcount2[i]!=0) || (charcount2[i]==0 && charcount1[i]!=0)) return false;
        }

        sort(charcount1.begin() , charcount1.end());
        sort(charcount2.begin() , charcount2.end());

        return charcount1 == charcount2;
    }
};