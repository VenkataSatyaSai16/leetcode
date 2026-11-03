class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> rank;
        for(int i = 0 ; i < arr2.size() ; i++){
            rank[arr2[i]] = i;
        }

        sort(arr1.begin() , arr1.end() , [&](int a , int b){
            bool aIn = rank.count(a);
            bool bIn = rank.count(b);
            if(aIn && bIn) return rank[a] < rank[b];
            if(aIn) return true;
            if(bIn) return false;
            return a<b;
        });

        return arr1;
    }
};