class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int low = 0, high = n - 1;
        long long moves = 0;

        while(low < high) {
            moves += nums[high] - nums[low];
            low++;
            high--;
        }

        return moves;
    }
};