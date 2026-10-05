class Solution {
public:
    bool predicate(long long k,int n){
        long long coins = 0 ;
        coins = ((k) * (k+1)) / 2;
        return coins<=n;
    }

    int arrangeCoins(int n) {
        long long left = 0 , right = 1LL+n;

        while(left+1<right){
            long long mid = (right-left)/2 + left;
            if(predicate(mid,n)) left = mid;
            else right=mid;
        }
        return left;
    }
};