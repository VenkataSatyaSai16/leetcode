class Solution {
public:
    bool predicate(vector<int> &candies, long long limit, long long k){
        long long validChildren = 0;
        for(int i = 0 ; i < candies.size() ; i++){
            validChildren += (candies[i])/limit;
        }
        return validChildren>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 0 , high = *max_element(candies.begin(),candies.end());

        while(low+1<high){
            long long mid = low + (high-low)/2;
            if(predicate(candies,mid,k)) low = mid;
            else high=mid;
        }
        if(predicate(candies,high,k)) return high;
        return low;
    }
};