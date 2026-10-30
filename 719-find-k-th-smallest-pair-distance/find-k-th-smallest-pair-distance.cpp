class Solution {
public:
    long long diff(long long first, long long second) { return second - first; }
    bool predicate(vector<int>& nums, long long low, long long mid, int k) {
        // Find Pairs
        int pairs = 0, n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            while (diff(nums[i], nums[j]) > mid) {
                i++;
            }
            pairs += (j - i);
            j++;
        }
        return pairs >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        long long n = nums.size();

        sort(nums.begin(), nums.end());

        long long low = 0, high = nums[n - 1] - nums[0];

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (predicate(nums, low, mid, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};