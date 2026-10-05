class Solution {
public:
    bool predicate(double mid , int num){
        if(mid*mid-(double)num>0) return true;
        return false;
    }

    bool isPerfectSquare(int num) {
        double left = 0.0 , right = (double)num+1.0;
        int trials = 100;
        while(left<right && trials--){
            double mid = (right-left)/2.0 + left;
            if(predicate(mid,num)) right = mid;
            else left = mid;
        }
        int sqrt = right;
        return sqrt*sqrt-num==0;
    }
};