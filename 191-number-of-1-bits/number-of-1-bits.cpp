class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
/*
Time: O(m), where m is the number of 1s.
Space: O(1)
*/

