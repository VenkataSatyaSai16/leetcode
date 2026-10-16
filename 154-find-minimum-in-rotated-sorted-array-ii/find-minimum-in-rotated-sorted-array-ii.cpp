class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimumNumber = INT_MAX;

        for(int i : nums){
            minimumNumber = min(i,minimumNumber);
        }

        return minimumNumber;
    }
};