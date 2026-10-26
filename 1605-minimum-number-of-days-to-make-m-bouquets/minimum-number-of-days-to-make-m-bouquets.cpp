class Solution {
public:
    bool predicate(vector<int>& Day , int days, int m , int k){
        int b = 0, consecutive = 0;
        for (int i = 0; i < Day.size(); i++) {
            if (Day[i] <= days) {
                consecutive++;
                if (consecutive == k) {
                    b++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return b >= m;;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size()) return -1;

        long long low = 1 , high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low+1<high){
            long long mid = low + (high-low)/2;
            if(predicate(bloomDay,mid,m,k)) high = mid;
            else low = mid;
        }
        if (predicate(bloomDay, low, m, k)) return (int)low;
        return (int)high;
    }
};