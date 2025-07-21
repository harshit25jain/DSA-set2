class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1 , 0);
        for(int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] ^ arr[i];
        int m = queries.size();
        vector<int> res(m , 0);
        for(int j = 0; j < m; ++j) res[j] = prefix[queries[j][1] + 1] ^ prefix[queries[j][0]];
        return res;
    }
};