class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i : arr){
            mp[i]++;
        }
        unordered_set<int> st;
        for(auto& [key,value] : mp){
            if(st.count(value)) return false;
            st.insert(value);
        }
        return true;
    }
};