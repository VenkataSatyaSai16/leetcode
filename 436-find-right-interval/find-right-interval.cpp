class Solution {
public:

    int findIndex(vector<pair<int,int>> &starts , int target){
        int n = starts.size();
        int low = -1 , high = n;
        while(low+1<high){
            int mid = low + (high-low)/2;
            if(starts[mid].first < target) low = mid;
            else high = mid;
        }
        if(high==n) return -1;
        return starts[high].second;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> starts;

        for(int i = 0 ; i < n ; i++){
            starts.push_back({intervals[i][0],i});
        }

        sort(starts.begin() , starts.end());

        vector<int> answer(n,-1);
        for(int i = 0 ; i < n ; i++){
            int index = findIndex(starts,intervals[i][1]);
            if(index>=0 && index<n){
                answer[i] = index;
            }
        }
        return answer;
    }
};