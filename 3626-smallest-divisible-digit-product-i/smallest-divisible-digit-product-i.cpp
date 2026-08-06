class Solution {
public:
    int digitProduct(int n){
        int sum = 1;
        while(n!=0){
            sum *= n%10;
            n/=10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        int i ;
        for(i = n ; i <= 100 ; i++){
            if(digitProduct(i)%t==0){
                return i;
            }
        }
        return -1;
    }
};