class Solution {
public:
    int minExtraChar( string &s, vector<string>& dictionary) {
        int dp[51] = {}; // Initialize an array to store the minimum extra characters.
        int n = s.size();
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1]; // Initialize with one extra character.
            
            for (const auto &w : dictionary) {
                if (i + w.size() <= n && s.compare(i, w.size(), w) == 0) {
                    dp[i] = min(dp[i], dp[i + w.size()]); // Update if a word in the dictionaryionary is found.
                }
            }
        }
        
        return dp[0]; // Return the minimum extra characters for the entire string.
    }

};
/*
Start iterating through the string s from the end (right to left).
For each position i, initialize dp[i] with a value of 1 + dp[i + 1]. This represents breaking the string after the current character and adding one extra character to the minimum extra characters found in the next position.
Check for each word in the dictionary if it matches the substring starting from the current position i. If a match is found, update dp[i] to the minimum between its current value and dp[i + w.size()], where w.size() is the length of the matched word.
Continue this process for all positions in the string s, and the final value of dp[0] will represent the minimum number of extra characters left over.


Time Complexity (TC): O(NML), where N is the length of the input string s, M is the number of words in the dictionary, and L is the average length of words in the dictionary.
Space Complexity (SC): O(N), where N is the length of the input string s. We use an array dp of size N to store the minimum extra characters at each position.

*/

