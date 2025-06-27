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

/*
First, build a simple target frequency map that we will use to check for permutations on s1.
Use a sliding window of size s1.size() across s2, maintaining a running frequency map (mapS2) for the current window. As the window expands, add the new character on the right.
If the size of our current window becomes larger than the size of s1, shrink the window by:
Decrementing the frequency of the character on the left side of the window. If the frequency becomes zero, remove it from the map of s2.
And, incrementing the left index of our window.
Finally, with the two substrings now equal in size, 
check if the two hash tables are the same. Return true if they match exactly.
If, after our right side pointer reaches the end of s2, we still don't have matching hash tables, return false.
*/
