class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();

        sort(nums.begin(),nums.end()); //sorting the array
        

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue; //skip duplicates

            int left=i+1,right=n-1;
            while(left<right){
                int sum = nums[i] + nums[left] +nums[right];

                if(sum  == 0){
                    result.push_back({nums[i],nums[left],nums[right]});

                    //move left ptr ahead 
                    while (left < right && nums[left] == nums[left + 1]) left++;
                // Move right pointer back while avoiding duplicates
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;  // Need a larger sum
            } else {
                right--; // Need a smaller sum
            }
        }
    }

    return result;
        
    }
};