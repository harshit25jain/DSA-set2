
//-------------------BFS Approach-------------------

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;

        if(ans[sr][sc] == color)
            return ans;

        queue<pair<int, int>> q;
        q.push({sr,sc});
        int initial = ans[sr][sc];
        ans[sr][sc] = color;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==initial) {
                    q.push({nrow, ncol});
                    ans[nrow][ncol] = color;
                }
            }
        }
        return ans;
    }
};

/*

Create the ans matrix equal to given image matrix.
Create base case as if(ans[sr][sc] == color), that is if given point already has newcolor return ans matrix as it is.
Create queue (pair) data structure to store node.
Push the initial node in queue q.
Create inital variable as ans[sr][sc] and update that node to new color as color.
Create array drow and dcol for traversal in different neighboring sides from node.
Iterate using while loop till queue is not empty.
Initialize row (r) and column (c) of front of queue and pop q.
Use for loop to iterate in each four directions and if condition, if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==initial) satisfies, push nrow and ncol in queue q and update ans[nrow][ncol] as color.
Finally return ans.

Time complexity: O(N∗M) : N = row, M = column
Space complexity: O(N∗M) : N = row, M = column

*/

