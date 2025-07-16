class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int> odd;
        priority_queue<int , vector<int> , greater<int>> even;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i & 1) odd.push(nums[i]);
            else even.push(nums[i]);
        }
        for(int i = 0; i < n; ++i){
            if(i & 1){
                nums[i] = odd.top();
                odd.pop();
            }
            else{
                nums[i] = even.top();
                even.pop();
            }
        }
        return nums;
    }
}; 
/*
APPROACH
Traverse the array and push elements at:
Even indices into a min-heap (even).
Odd indices into a max-heap (odd).
Iterate through the array again, and:
Assign from even.top() to even indices, and pop.
Assign from odd.top() to odd indices, and pop.
*/ 