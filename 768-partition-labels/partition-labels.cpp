class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastOcc(26, -1);
        int n = s.length();
        for(int i=0; i<n; i++){
            lastOcc[s[i]-'a']=i;
        }
        vector<int>ans;
        int curr = 0;
        int l=0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            l = max(l, lastOcc[ch-'a']);
            curr++;
            if(i==l){
                ans.push_back(curr);
                curr =0;
            }
            

        }
        return ans;

    }
};