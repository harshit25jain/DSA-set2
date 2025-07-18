class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (to_string(nums[i]).size() % 2 == 0)
                res++;
        }
        return res;
    }
};
/*
Loop through each number in the array.
Convert the number to a string using to_string().
If the length of that string is even, increase the count.
Return the total count at the end.

*/

