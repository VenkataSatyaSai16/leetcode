class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};
        int size = s.size(), num = 0;
        for (int i = 0; i < size; i++) {
            if (i + 1 < size && mp[s[i]] < mp[s[i + 1]]) {
                num -= mp[s[i]];
            } else {
                num += mp[s[i]];
            }
        }
        return num;
    }
};