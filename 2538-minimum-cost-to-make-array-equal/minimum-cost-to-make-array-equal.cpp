class Solution {
public:
    long long predicate(vector<int>& nums, vector<int>& cost, long long x) {
        long long totalCost = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalCost += (long long)abs(nums[i] - x) * cost[i];
        }
        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long low = *min_element(nums.begin(), nums.end()),
                  high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long cost1 = predicate(nums, cost, mid);
            long long cost2 = predicate(nums, cost, mid + 1);
            if (cost1 > cost2)
                low = mid + 1;
            else
                high = mid;
        }
        return predicate(nums,cost,low);
    }
};