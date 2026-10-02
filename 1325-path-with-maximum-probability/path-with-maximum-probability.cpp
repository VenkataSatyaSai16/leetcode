class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //i - {{j1,wt} , {j2,wt}}
        vector<vector<pair<int,double>>> Edges(n);
        for(int i = 0 ; i < succProb.size() ; i++){
            Edges[edges[i][0]].push_back({ edges[i][1] , succProb[i]});
            Edges[edges[i][1]].push_back({edges[i][0] , succProb[i]});
        }
        vector<double> probs(n,DBL_MIN);
        priority_queue< pair<double,int> , vector<pair<double,int>> > pq;

        probs[start_node] = 1.0;
        pq.push({ 1.0 , start_node});

        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            //cout<<"{"<<node<<" - "<<prob<<"}\n";
            pq.pop();
            if(node==end_node){
                return prob;
            }

            for(auto &e : Edges[node]){
                double newProb = prob*e.second;
                if(newProb>probs[e.first]){
                    probs[e.first] = newProb;
                    pq.push({newProb,e.first});
                }
            }
        }
        return 0.0;
    }
};