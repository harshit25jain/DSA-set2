class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        
        for(int i = 0; i < n; i++){
            pq.push({mat[i][0], i, 0});
        }
        
        int count = 0, ans = -1;
        
        while(count < k){
            auto top = pq.top();
            pq.pop();
            count++;
            ans = top[0];
            int r = top[1];
            int c = top[2];
            if(c + 1 < n){
                pq.push({mat[r][c + 1], r, c + 1});
            }
        }
        
        return ans;
    }
};
/*
Time complexity:
O(k × log(n))
At most k elements pushed/popped in the heap, each operation takes O(log n) time.
Space complexity:
O(n)
The heap stores up to n elements at any time.
*/
