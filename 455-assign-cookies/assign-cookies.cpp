class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int m = g.size();
        int n = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l = 0, r = 0;

        while(l<n && r<m){

            if(g[r]<=s[l]){
                r++;
            }
            l++;
        }

        return r;
    }
};

/* O(nlogn) since we sorted the arrays
a) sort both the arrays in ascending order
b) traverse both of them using 2 pointers.
c) the right pointer is moved if the greed is satisfied by a cookie, but the left pointer moves regardless
this is true because if the left pointer cannot satisfy greed of lets say g[j], it wont satisfy g[j+1]
either since its sorted. at the end, return the right pointer
*/

