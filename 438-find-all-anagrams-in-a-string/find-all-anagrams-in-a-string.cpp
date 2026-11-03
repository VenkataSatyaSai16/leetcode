class Solution {
public:
    bool cmp(vector<int> &ar1 , vector<int> &ar2){
        for(int i = 0 ; i < 26 ; i++){
            if(ar1[i]!=ar2[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int size1 = s.size();
        int size2 = p.size();
        if(size1<size2) return {};
        vector<int> result;
        vector<int> charCount(26,0);
        for(char ch : p){
            charCount[ch-'a']++;
        }
        vector<int> charCount2(26,0);
        for(int i = 0 ; i < size2-1 ; i++){
            charCount2[s[i]-'a']++;
        }
        for(int i = size2-1 ; i < size1 ; i++){
            if(i-size2>=0){
                charCount2[s[i-size2]-'a']--;
            }
            charCount2[s[i]-'a']++;
            if(cmp(charCount,charCount2)){
                result.push_back(i-size2+1);
            }
        }
        return result;
    }
};