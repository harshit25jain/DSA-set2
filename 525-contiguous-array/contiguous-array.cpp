class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLen=0;
        unordered_map<int, int> seen{{0, -1}};
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]==1 ? 1 : -1;
            if(seen.count(sum)) maxLen = max(maxLen, i-seen[sum]);
            else seen[sum] = i;
        }
        return maxLen;
    }
};
/*
My approach is to use a prefix sum and a hashmap.
First, I treat every 0 in the array as -1 and every 1 as +1. 
This transforms the problem into finding the longest subarray with a sum of 0.
As I iterate through the array, I maintain a running sum. 
If I encounter the same sum again at a later index, it means
that the elements between those two indices cancel each other out — 
meaning there's an equal number of 0s and 1s in that subarray.
I use an unordered map to store the first occurrence of each running sum. Then, whenever the same sum appears again, 
I calculate the distance between the current index and the stored index, and update the maximum length accordingly.
This approach works in O(n) time and O(n) space, and it avoids the need for brute-force nested loops.”

*/
