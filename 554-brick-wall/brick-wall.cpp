class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long ,int> mp;

        int max_edges = 0;

        for(const auto& row : wall){
            long long edge_index = 0;

            for(int i = 0 ; i < row.size()-1;i++){
                edge_index+=row[i];
                mp[edge_index]++;
                max_edges = max(max_edges,mp[edge_index]);
            }
        }
        return wall.size() - max_edges;
    }
};