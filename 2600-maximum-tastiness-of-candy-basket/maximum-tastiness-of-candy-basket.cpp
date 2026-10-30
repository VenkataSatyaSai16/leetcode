class Solution {
public:
    bool predicate(vector<int>& price, int k, int mid) {
        int count = 1 , last = price[0];
        for(int i = 1 ; i < price.size() ; i++){
            if(price[i]-last>=mid){
                count++;
                last = price[i];
            }
        }
        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());

        int low = 0, high = price[n-1] - price[0];
        
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (predicate(price, k, mid))
                low = mid;
            else
                high = mid;
        }
        if (predicate(price, k, high))
            return high;

        return low;
    }
};