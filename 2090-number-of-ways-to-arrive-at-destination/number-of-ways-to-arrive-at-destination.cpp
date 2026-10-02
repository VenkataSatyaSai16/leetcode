class Solution {
public:
    long long mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> edges(n);
        for(int i = 0 ; i < roads.size() ; i++){
            edges[roads[i][0]].push_back({ roads[i][1] , 1LL*roads[i][2] });
            edges[roads[i][1]].push_back({ roads[i][0] , 1LL*roads[i][2] });
        }
        vector<long long> times(n,1e18);
        vector<long long> ways(n,0);
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > pq;

        times[0] = 0LL;
        ways[0] = 1LL;
        pq.push({ 0, 0 });

        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (time > times[node]) continue;
            
            for(auto &edge : edges[node]){
                long long newtime = edge.second;
                int newnode = edge.first;

                long long totalTime = time + newtime;
                if(totalTime == times[newnode] ){
                    ways[newnode] =  (ways[newnode] +ways[node]) % mod;

                } else if(totalTime < times[newnode]){
                    ways[newnode] = ways[node];
                    times[newnode] = totalTime;
                    pq.push({totalTime , newnode});
                }
                
            }
        }
        ways[n-1] = ways[n-1]%mod;
        return (int)ways[n-1];
    }
};