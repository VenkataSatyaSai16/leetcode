class Solution {
public:
    void find_combinations(int index , int n , vector<int> &candidates,int target,vector<int> &combination , vector<vector<int>> &combinations){
        if(target==0){
            //Insert
            vector<int> temp = combination;
            sort(temp.begin(), temp.end());
            combinations.push_back(temp);
            return;
        }
        if(target<0)
            return;

        for(int i = index ; i < n ; i++){
            //Handle duplicates
            if(i > index && candidates[i] == candidates[i-1]) continue;
            //Add element
            combination.push_back(candidates[i]);
            find_combinations(i+1,n,candidates,target-candidates[i],combination,combinations);
            //Backtrack
            combination.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<int> combination = {};
        vector<vector<int>> combinations={};
        find_combinations(0,n,candidates,target,combination,combinations);
        return combinations;
    }
};
