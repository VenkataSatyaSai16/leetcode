class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<4) return {};

        sort(nums.begin(),nums.end());
        set<vector<int>> ans;

        for(int i = 0 ; i < n-3 ; i++){
            for(int j = i+1 ; j < n-2 ; j++){
                int sum = nums[i] + nums[j];
                int k = j+1 , l = n-1;
                while(k<l){
                    long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum>target){
                        l--;
                    } else{
                        k++;
                    }
                    
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};