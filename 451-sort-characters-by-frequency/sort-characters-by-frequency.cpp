class Solution {
public:
    static bool cmp(const pair<char,int>& a, const pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        vector<pair<char,int>> vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),cmp);

        string result = "";
        for(auto &[key , value] : vec){
            result.append(value,key);
        }
        return result;
    }
};