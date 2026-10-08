class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        //vector<char> ans;
        string ans = "";
        int count = 0, j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
                if (count == 0) {
                    //ans.insert(ans.end(), s.begin() + j + 1, s.begin() + i - j - 1);
                    ans += string_view(s).substr(j+1, i-j-1);
                    //cout<<ans<<"\t";
                    j = i + 1;
                }
            }
        }
        //string answer(ans.begin(), ans.end());
        return ans;
    }
};