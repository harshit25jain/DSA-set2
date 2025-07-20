
class Solution {
public:
    int countAtMostKOdds(std::vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }

        int left = 0;
        int current_odds_sum = 0;
        int total_subarrays = 0;

        for (int right = 0; right < nums.size(); ++right) {
            current_odds_sum += (nums[right] % 2);

            while (current_odds_sum > k) {
                current_odds_sum -= (nums[left] % 2);
                left++;
            }
            total_subarrays += (right - left + 1);
        }
        return total_subarrays;
    }

    int numberOfSubarrays(std::vector<int>& nums, int k) {
        return countAtMostKOdds(nums, k) - countAtMostKOdds(nums, k - 1);
    }
};