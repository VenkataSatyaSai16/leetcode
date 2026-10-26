class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0 , high = n-1;
        int ans = 0;
        while(low<=high){
            int mid = (high-low)/2 + low;
            int papers = n - mid;
            if(papers<=citations[mid]){
                high = mid-1;
                ans = papers;
            }
            else low = mid+1;
        }
        return ans;
    }
};