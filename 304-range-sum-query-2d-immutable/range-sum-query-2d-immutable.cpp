class NumMatrix {
public:
    vector<vector<long long>> PrefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        PrefixSum.assign(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                PrefixSum[i + 1][j + 1] = matrix[i][j] + PrefixSum[i][j + 1] +
                                          PrefixSum[i + 1][j] - PrefixSum[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return PrefixSum[row2 + 1][col2 + 1] + PrefixSum[row1][col1] -
               PrefixSum[row1][col2 + 1] - PrefixSum[row2 + 1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */