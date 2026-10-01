class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Dijkstra Algorithm to find the no. of levels in the path =(max in the
        // path - start / min in the path)
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        cost[0][0] = grid[0][0];
        pq.push({grid[0][0], 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            int x = u / n, y = u % n;
            if (x == n - 1 && y == n - 1) {
                return d;
            }

            for (auto& dir : dirs) {
                int dx = dir[0], dy = dir[1];

                int sx = x + dx, sy = y + dy;

                if (sx >= 0 && sx < n && sy >= 0 && sy < n) {
                    int nextCost = max(cost[x][y], grid[sx][sy]);

                    if (nextCost < cost[sx][sy]) {
                        cost[sx][sy] = nextCost;
                        pq.push({cost[sx][sy], sx * n + sy});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << cost[i][j] << " ";
            }
            cout << endl;
        }
        return cost[n - 1][n - 1];
    }
};