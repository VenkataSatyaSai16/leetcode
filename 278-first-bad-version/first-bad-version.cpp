// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0 , right = n;
        while(left+1<right){
            int mid = (right-left)/2 + left;
            if(isBadVersion(mid)) right=mid;
            else left=mid;
        }
        return left+1;
    }
};