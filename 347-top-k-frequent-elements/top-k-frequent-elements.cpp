class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }

        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        for(auto& [value,freq]: mp){
            pq.push({freq,value});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> answer;
        while(!pq.empty()){
            pair<int,int> pr = pq.top();
            pq.pop();
            answer.push_back(pr.second);
        }

        return answer;
    }
};