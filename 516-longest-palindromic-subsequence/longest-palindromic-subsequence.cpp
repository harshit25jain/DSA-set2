class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1= s;
        
        reverse(s1.begin(), s1.end());
        int n= s.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if( s[i-1]== s1[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
};
/*
reverse the original string.
Use a 2D DP table where dp[i][j] stores the length of the LCS of s[0..i-1] and reversed_s[0..j-1].
If characters match, dp[i][j] = 1 + dp[i-1][j-1].
If not, dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
Final answer is dp[n][n].
*/
