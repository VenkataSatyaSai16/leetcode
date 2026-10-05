class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //First occurence
        int left = -1 , right = n;
        while(left+1<right){
            int mid = (right-left)/2 + left;
            if(nums[mid]<target) left = mid; 
            else right = mid;
        } 
        int start = right;
        //Last occurence
        left = -1;
        right = n;
        while(left+1<right){
            int mid = (right-left)/2 + left;
            if(nums[mid]<=target) left = mid;
            else right = mid;
        }
        int end = left;
        //Array generation
        
        if((start>-1 && start<n) && (end>-1 && end<n)&&  (nums[start]!=target || nums[end]!=target)) return {};

        vector<int> result;
        for(int i = start ; i <= end ; i++){
            result.push_back(i);
        }

        return result;
    }
};