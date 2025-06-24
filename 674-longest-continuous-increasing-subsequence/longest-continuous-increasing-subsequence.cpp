class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1, ans = 1;
        for(int i = 1, n = nums.size(); i < n; ++i){
            if(nums[i - 1] < nums[i]){
                ++count;
                ans = max(ans , count);
            }
            else count = 1;
        }
        return ans;
    }
};
/*
1.Start with a count = 1 because any non-empty array has at least a length-1 subsequence.
2.Use a loop starting from the second element.
3.For each element:
If it's greater than the previous one, increment the current count.
If not, reset the count to 1.

4.Track the maximum length encountered using ans.
5.Return the maximum found.*/
