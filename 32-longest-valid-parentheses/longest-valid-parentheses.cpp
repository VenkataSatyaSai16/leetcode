class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        //left valid 
        int left_max = 0;
        int left = 0 , right = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='(')left++;
            else right++;
            if(left==right){
                left_max = max(left_max,left+right);
            } else if(right>left){
                left = 0 ;
                right = 0;
            }
        }
        //right valid
        left = right = 0;
        int right_max = 0;
        for(int i = n-1 ; i >= 0 ;i--){
            if(s[i]=='(') left++;
            else right++;
            if( left == right ){
                right_max = max(right_max , left+right);
            } else if(left>right){
                left = right = 0;
            }
        }
        return max(left_max,right_max);
    }
};