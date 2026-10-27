class Solution {
public:
    bool predicate(vector<int>& time , long long t , int totalTrips){
        long long trips = 0;
        for(int i = 0 ; i < time.size() ; i++){
            trips += t/time[i];
        }
        return trips>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        long long low = 1 , high = (long long)*max_element(time.begin(), time.end())*totalTrips;

        if(predicate(time,low,totalTrips)) return low;

        while(low+1<high){
            long long mid = low + (high-low)/2;
            if(predicate(time,mid,totalTrips)) high = mid;
            else low = mid;
        }
        return high;
    }
};