class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        set<string> foodItems;

        map<int , map<string,int>> tableCounts;

        for(const auto& order : orders){
            int table = stoi(order[1]);
            string dish = order[2];

            foodItems.insert(dish);
            tableCounts[table][dish]++;
        }

        vector<vector<string>> result;

        vector<string> header;
        header.push_back("Table");

        for(auto& item : foodItems){
            header.push_back(item);
        }

        result.push_back(header);

        for(const auto& [table,counts] : tableCounts) {
            vector<string> row;
            row.push_back(to_string(table));

            for(auto& item : foodItems){
                if(counts.find(item)!=counts.end()){
                    row.push_back(to_string(counts.find(item)->second));
                } else{
                    row.push_back("0");
                }
            }
            result.push_back(row);
        }
        return result;
        
        

        


    }
};