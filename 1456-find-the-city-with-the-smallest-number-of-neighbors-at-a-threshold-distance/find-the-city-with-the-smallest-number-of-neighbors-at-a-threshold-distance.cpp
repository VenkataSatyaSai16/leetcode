class Solution {
public:

    vector<int> djk(int src ,vector<vector<pair<int,int>>> &edges , int n){
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto &edge : edges[u]){
                int w = edge.second;
                int v = edge.first;

                if(dist[u]+w<dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v] , v});

                }
            }
        }
        return dist;

    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //convert edges into adj list.
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0 ; i < edges.size() ; i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int weight = edges[i][2];

            adj[src].push_back({dest,weight});
            adj[dest].push_back({src,weight});
        }

        int minCity = -1;
        int minCount = n;
        for(int i = 0 ; i < n ; i++){
            vector<int> dist = djk(i,adj,n);
            int count = 0;
            for(int j = 0 ; j < n ; j++){
                if(dist[j]<=distanceThreshold){
                    count++;
                }
            }

            if(count==minCount && i > minCity){
                minCity = i ;
            }
            else if(count<minCount){
                minCount = count;
                minCity = i;
            } 
        }
        return minCity;
    }
};