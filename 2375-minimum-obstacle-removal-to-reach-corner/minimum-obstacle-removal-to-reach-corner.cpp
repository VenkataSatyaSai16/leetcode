class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        cost[0][0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            int x = u / n, y = u % n;

            for (auto& dir : dirs) {
                int dx = dir[0], dy = dir[1];
                int sx = x + dx, sy = y + dy;

                if (sx >= 0 && sx < m && sy >= 0 && sy < n) {

                    int newCost = d + grid[sx][sy];
                    if (newCost < cost[sx][sy]) {
                        cost[sx][sy] = newCost;
                        pq.push({newCost, sx * n + sy});
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << cost[i][j] << " ";
            }
            cout << endl;
        }
        return cost[m - 1][n - 1];
    }
};