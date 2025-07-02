class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
/*
Create a set to keep track of numbers we've already seen during the transformation process.
For each number:
Break it into digits.
Compute the sum of the squares of its digits.
If we reach 1, return true.
If we've already seen the number, a cycle is detected, so return false.

Time complexity: O(logn) per iteration, because we process each digit in the number
Space complexity: O(n) for storing previously seen numbers in a set.
*/