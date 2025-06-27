class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1 ; i<nums.size() ; i++){
            int take = nums[i]+prev2;
            int not_take = prev;
            int curr = max(take,not_take);
            prev2 = prev;
            prev = curr; 
        }
        return prev;
    }
};