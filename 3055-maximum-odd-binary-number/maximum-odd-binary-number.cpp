class Solution {
public:
    string maximumOddBinaryNumber(string s) {
/*
Time complexity:
O(n)
Space complexity:
O(n)
 */
        int cnt1 = 0, cnt0 = 0;
        for (auto a : s) {
            if (a == '1') cnt1++;
            else if (a == '0') cnt0++;
        }
        string ans = string(cnt1 - 1, '1') + string(cnt0, '0') + '1';
        return ans;
    }
};


/*
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]=='1')swap(s[i],s[s.size()-1]);
        }
        return s;
    }
};
Time complexity:
O(nlogn)

Space complexity:
O(1)

*/