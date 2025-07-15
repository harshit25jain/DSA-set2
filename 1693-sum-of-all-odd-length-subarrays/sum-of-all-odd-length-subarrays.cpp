class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i=0;i<arr.size();i++){
            int left = i+1;
            int right = n-i;

            int totalSum = left * right;
            int SubArraySum = (totalSum + 1) / 2;

            count += arr[i] * SubArraySum;
        }
        return count;
    }
};

/*
For each element at index i, calculate:
left = i + 1 → Number of choices to start the subarray
right = n - i → Number of choices to end the subarray
Total subarrays including arr[i] = left * right
About half of these subarrays will be of odd length, calculated as (left * right + 1) / 2
Multiply the element's value by the number of odd-length subarrays it contributes to,
and add it to the total sum.
*/