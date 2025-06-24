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