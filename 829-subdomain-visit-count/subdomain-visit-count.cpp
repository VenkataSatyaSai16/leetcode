class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> map;

        for(const string& str : cpdomains){
            
            int spaceIdx = str.find(' ');
            int freq = stoi(str.substr(0,spaceIdx));
            string domain = str.substr(spaceIdx+1);

            map[domain]+=freq;

            for(int i = 0 ; i < domain.length() ; i++){
                if(domain[i]=='.'){
                    string subdomain = domain.substr(i+1);
                    map[subdomain]+=freq;
                }
            }
        }
        
        vector<string> result;
        for(auto &[domain,count]:map){
            result.push_back(to_string(count)+ " " + domain);
        }
        return result;
    }
};