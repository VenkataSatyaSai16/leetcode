class Solution {
public:
    void bfs(int start , vector<int> &visited ,vector<vector<int>> &adj ){
        queue<int> que;
        que.push(start);
        visited[start] = 1;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int v : adj[node]){
                if(!visited[v]){
                    visited[v] = 1;
                    que.push(v);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> result;
        //Build the adj list
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < invocations.size() ; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }
        //BFS
        vector<int> visited(n,0);

        bfs(k,visited,adj);
        bool canRemove = true;
        for(int i = 0 ; i < invocations.size() ; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            if(!visited[u] && visited[v]){
                canRemove = false;
            }
        }
        if(canRemove){
            for(int i = 0 ; i < n ; i++){
                if(!visited[i]){
                    result.push_back(i);
                }
            }
        } else{
            for(int i = 0 ; i < n ; i++){
                result.push_back(i);
            }
        }
        
        return result;
    }
};