class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int totalRotations = 0;
        int from = 0;
        for(int i = 0 ; i < n ; i++){
            int to = s[i]-'0';
            int minRotation = min(abs(from-to) , 10-abs(from-to));
            totalRotations+=minRotation;
            from = to;
        }
        return totalRotations;
    }
};