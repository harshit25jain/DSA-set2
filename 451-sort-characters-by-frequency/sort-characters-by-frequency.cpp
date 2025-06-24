class Solution {
public: 
//TC: O(N), SC:O(N) WITHOUT SORTING
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};

/*
We use a bucket sort approach:
Count the frequency of each character.
Use an array of strings (bucket[]) where bucket[i] holds all characters that occur i times.
Since max frequency can be at most s.size(), we go from highest to lowest to build the result.
*/
