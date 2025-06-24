class Solution {
public:
    int longestPalindrome(string s) {
     map<char,int> a;
     for(char c:s) a[c]++;  
     int ans=0,k=0;
     for(auto i:a){
        if(i.second%2==0) ans+=i.second; //when count of char is even
        else {
            ans+=i.second-1; //when count of char is odd
            k=1;}}
     if(k==1) ans++;
     return ans;
    }
};
