class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : s) { 
            if (!s.count(num - 1)) {
                int curr = num, len = 1;
                while (s.count(curr + 1)) {
                    curr++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
/*
Insert all numbers into an unordered set to allow for O(1) lookups.
Iterate over the set and, for each number, check if it is the start of a sequence (i.e., num-1 is not present).
If it is a start, incrementally check for num+1, num+2, ... and count the sequence length.
Update the maximum length whenever a longer sequence is found.
*/
