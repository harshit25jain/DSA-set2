
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n=arr.size();
    vector<int>dp(n+1,0);
    dp[n]=0;
    //✅ i=(n-1,0)
    for(int i=n-1;i>=0;i--){
      int maxi=-1e9;//✅ correct position to initialize under first loop
      int maxsum=-1e9;//✅ correct position 
      for(int ind=i;ind<min(i+k,n);ind++){
        maxi=max(maxi,arr[ind]);
        int sum=maxi*(ind-i+1)  +dp[ind+1];
        maxsum=max(maxsum,sum);
        dp[i]=maxsum;
    }  
    } 
    return dp[0];// 
    }
};