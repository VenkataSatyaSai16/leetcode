class Solution {
public:
    bool pred(int a , int b){
        return a<b;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int l = -1 , r = n;

        while(l+1<r){
            int mid = l + (r-l)/2;
            cout<<mid<<endl;
            if(pred(nums[mid],target)) l = mid;
            else r = mid;
        }
        return r;
    }
};