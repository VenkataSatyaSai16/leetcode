class Solution {
public:
    int max_element(vector<vector<int>> &heights){
        int maxEl = heights[0][0];
        int n = heights.size() , m = heights[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                maxEl = max(maxEl,heights[i][j]);
            }
        }
        return maxEl;
    }

    int min_element(vector<vector<int>> &heights){
        int minEl = heights[0][0];
        int n = heights.size() , m = heights[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                minEl = min(minEl,heights[i][j]);
            }
        }
        return minEl;
    }

    bool predicate(vector<vector<int>>& heights , int k){
        int n = heights.size();
        int m = heights[0].size();
        int length = n*m;

        vector<bool> djk(length,false);
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};

        priority_queue<int , vector<int> , greater<int>> pq;

        djk[0] = true;
        pq.push(0);

        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            int x = u/m ;
            int y = u%m;

            for(auto &dir : dirs){
                //ROW*N+COL
                int dx = dir[0];
                int dy = dir[1];
                int sx = x+dx , sy = y+dy;
                if(sx >= 0 && sx < n && sy >= 0 && sy < m){
                    int diff = abs(heights[x][y] - heights[sx][sy]);
                    int v = sx*m+sy;
                    if(diff<=k && !djk[v]){
                        djk[v] = true;
                        pq.push(v);
                    }
                }
            }
        }
        return djk[length-1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        //Binary Search on K + dijkstra 
        //Min Max BS
        int mx = max_element(heights);
        int mn = min_element(heights);

        int low = 0 , high = mx-mn+1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(predicate(heights,mid)) high = mid;
            else low = mid+1; 
        }
        return low;
    }
};