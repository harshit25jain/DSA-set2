class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++)  
            sum += nums[i];

        int maxSum = sum;

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];  
        maxSum = max(maxSum, sum);
        }
        
        return (maxSum * 1.0) / (k * 1.0);
    }
};
/*
Compute the sum of the first k elements.
Use a sliding window: for each element after index k, subtract the element going out of the window and add the new one.
Keep track of the maximum sum seen.
Return the maximum average by dividing max sum by k.
*/
