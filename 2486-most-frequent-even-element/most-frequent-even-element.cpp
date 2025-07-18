class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int ans = -1;
        int maxFreq = 0;
        int n = nums.size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                mpp[nums[i]]++;
            }
        }
        for (auto it : mpp) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};