#include <unordered_map>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mapS1;
        for (char c:s1) mapS1[c]++;

        unordered_map<char, int> mapS2;
        int left=0;
        for (int right=0; right<s2.size(); right++) { 
            mapS2[s2[right]]++;
            if (right-left+1>s1.size()) {
                mapS2[s2[left]]--;
                if (mapS2[s2[left]] == 0) mapS2.erase(s2[left]);
                left++;
            }
            if (mapS2==mapS1) return true;
        }
        return false;
    }
};