class Solution {
public:
    bool predicate(double mid , double x){
        if(mid*mid-x>0) return true;
        return false;
    }

    int mySqrt(int x) {
        double left = -1.0 , right = x+1.0;
        int trials = 100;

        while(left<right && trials--){
            double mid = (right-left)/2.0 + left;
            if(predicate(mid,x)) right = mid;
            else left = mid;
        }

        return right;

    }
};