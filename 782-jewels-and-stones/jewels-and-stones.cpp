class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;
        for(char ch : jewels){
            set.insert(ch);
        }

        int count = 0;
        for(char ch : stones){
            if(set.count(ch)==1) count++;
        }
        return count;
    }
};