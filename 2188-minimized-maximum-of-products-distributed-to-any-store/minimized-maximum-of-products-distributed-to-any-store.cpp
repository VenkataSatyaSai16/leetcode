class Solution {
public:
    bool predicate(vector<int>& quantities , int quant , int n){
        int shops = 0;
        for(int i = 0 ; i < quantities.size() ; i++){
            shops+= (quantities[i]+quant-1) / quant;
        }
        return shops<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        long long low = 0 , high = *max_element(quantities.begin(),quantities.end());

        while(low+1<high){
            long long mid = low + (high-low)/2;
            if(predicate(quantities,mid,n)) high = mid;
            else low = mid;
        }

        return high;
    }
};