class Solution {
public:
    int longestPalindrome(string s) {
     map<char,int> a;
     for(char c:s) a[c]++; //stores the count of each char
     int ans=0, k=0;
     for(auto i:a){
        if(i.second%2==0) 
            ans+=i.second; //when count of char is even
        else {
            ans+=i.second-1; //when count of char is odd
            k=1;
        }}
     if(k==1) ans++;
     return ans;
    }
};
/*
1.I first count the frequency of each character using a map. 
2.For building a palindrome, I add the full count of all even-frequency characters. 
3.For odd frequencies, I use count - 1 so that it becomes even and fits on both sides of the palindrome.
4.If there’s at least one odd-count character, I add 1 to place it in the center.
5.This ensures I get the maximum possible palindrome length.
6.The variable k acts as a flag to track if any character has an odd frequency.*/
