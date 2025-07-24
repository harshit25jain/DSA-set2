class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> prefix(n), res;
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + nums[i];
        for (int j = 0, m = queries.size(); j < m; ++j) {
            int idx = upper_bound(prefix.begin(), prefix.end(), queries[j]) - prefix.begin();
            res.push_back(idx);
        }
        return res;
    }
};