class Solution {
public:
    

    bool checkValidString(string s) {
        int n = s.size();
        if(n==1){
            if(s[0]=='*'){
                return true;
            }
            return false;
        }
        int cmax = 0 , cmin = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i]=='('){
                cmax++;
                cmin++;
            }
            else if(s[i]==')'){
              cmin--;  
              cmax--;
            } 
            else {
                cmax++;
                cmin--;
            }
            if(cmax<0) return false;
            if(cmin<0) cmin=0;
        }
    

        return cmin==0;    
    }
};