class Solution {
public:
  /*Time complexity:
O(N*N)
Space complexity:
O(N) - Dp grid*/
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

       vector<int> dp(n+1,0);
        for(int i = n-1 ; i >= 0 ;i--){
            for(int prev = i-1 ; prev >= -1 ; prev--){
                int take = 0;
       
                if(prev == -1 ||nums[i] > nums[prev]) take = 1 + dp[i+1];
                int ntake = dp[prev+1];
                 dp[prev+1] = max(take,ntake);
            }
        }
        return dp[-1+1];
    }
};

/*
class Solution {
public:
  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

       vector<int> dp;
       dp.push_back(nums[0]);
        for(int i = 1 ; i < n ;i++){
                
                if(nums[i] > dp.back()){
                    dp.push_back(nums[i]);
                }
                else{
                    int lb = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                    dp[lb] = nums[i];
                }
            
        }
        return dp.size();
    }
};
Time complexity:
O(N*log(N)) -> N loop + Binary Search
Space complexity:
O(N) - Dp array

*/