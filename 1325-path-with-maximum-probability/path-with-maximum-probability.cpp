class Solution {
public:
    struct Edge{
        int src;
        int dest;
        double weight;
    };

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<Edge> Edges;
        for(int i = 0 ; i < succProb.size() ; i++){
            Edges.push_back({edges[i][0] , edges[i][1] , succProb[i]});
            Edges.push_back({edges[i][1] , edges[i][0] , succProb[i]});
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

            for(Edge e : Edges){
                if(e.src==node){
                    double newProb = prob*e.weight;
                    if(newProb>probs[e.dest]){
                        probs[e.dest] = newProb;
                        pq.push({newProb,e.dest});
                    }
                } else if(e.dest==node){
                    double newProb = prob*e.weight;
                    if(newProb>probs[e.src]){
                        probs[e.src] = newProb;
                        pq.push({newProb,e.src});
                    }
                }
            }
        }
        return 0.0;
    }
};