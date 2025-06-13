class Solution {
public:
    string largestOddNumber(string num) {
        string s="", res="";
         for(int i=0; i<num.size(); i++){
             s += num[i]; 
             if((num[i]-'0') % 2 == 1) res = s;
         }
        return res;
    }
};