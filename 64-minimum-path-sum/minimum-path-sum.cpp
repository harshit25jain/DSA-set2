class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,INT_MAX));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int val = INT_MAX;
                if(i-1 >=0) val = min(val, dp[i-1][j]);
                if(j-1 >=0) val = min(val, dp[i][j-1]);

                dp[i][j] = val+ grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

/*
//Recursion - TLE
class Solution {
public:
    int recur(int x, int y, int m, int n, vector<vector<int>>&grid){
        if(x>=m || y>=n) return INT_MAX;

        if(x==m-1 && y==n-1)return grid[x][y];

        //Right
        int right = recur(x, y+1, m, n, grid);
        //Down
        int down = recur(x+1, y, m, n, grid);
        return (min(right,down))+ grid[x][y];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return recur(0, 0, m, n, grid);
    }
};
*/