class Solution {
public:
    struct Comparator{
        bool operator()(const pair<int,string>& a , const pair<int,string>& b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string str : words){
            mp[str]++;
        }

        priority_queue<pair<int,string> , vector<pair<int,string>> , Comparator > pq;

        for(auto &[str,freq] : mp){
            pq.push({freq,str});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<string> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};