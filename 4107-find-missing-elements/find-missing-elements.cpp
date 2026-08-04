class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = nums[0];
        int high = nums[n-1];
        vector<int> result = {};
        int pointer = 0;
        for(int i = low ; i < high ; i++){
            if(i==nums[pointer]){
                pointer++;
            }else{
                result.push_back(i);
            }
        }
        return result;
    }
};