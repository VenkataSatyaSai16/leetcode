class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int,vector<int>> adj;

        for(const auto& pair : adjacentPairs){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        int startNode = 0;
        for(const auto& [node,neighbors] : adj){
            if(neighbors.size()==1){
                startNode = node;
                break;
            }
        }

        int n = adjacentPairs.size() + 1;

        vector<int> result;

        result.reserve(n);

        int prev = -1e9;
        int curr = startNode;

        for(int i = 0 ; i < n ; i++){
            result.push_back(curr);

            for(int neighbour : adj[curr]){
                if(neighbour!=prev){
                    prev = curr;
                    curr = neighbour;
                    break;
                }
            }
        }
        return result;
    }
};