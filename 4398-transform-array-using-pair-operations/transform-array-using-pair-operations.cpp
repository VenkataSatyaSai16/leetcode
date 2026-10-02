class Solution {
public:
    long long sum(vector<int>& arr){
        long long TotalSum = 0LL;
        for(int num : arr){
            TotalSum+= (1LL*num);
        }
        return TotalSum;
    }

    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sourceSum = sum(source);
        long long targetSum = sum(target);
        return sourceSum == targetSum;
    }
};