class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0 ; i<n ; i++){
            if(s[i]=='('){
                st.push(0);
            } else{
                int score = st.top();
                st.pop();
                int temp = 0;
                if(!st.empty()){
                  temp = st.top();  
                  st.pop();
                } 
                if(score==0){
                    st.push(temp+1);
                } else{
                    st.push(temp + 2*score);
                }
            }
        }
        int score = 0;
        while(!st.empty()){
            score+=st.top();
            st.pop();
        }
        return score;
    }
};