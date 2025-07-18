class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        vector<int>mpp(10,0);

        for(auto it : digits){
            mpp[it]++;
        }

        for(int i = 1 ; i <= 9 ; i++){
            if(mpp[i] == 0)continue;
            mpp[i]--;
            for(int j = 0 ; j <= 9 ; j++){
                if(mpp[j] == 0)continue;
                   mpp[j]--;
                for(int k = 0 ; k <= 8 ; k+=2){
                    if(mpp[k] == 0)continue;
                       mpp[k]--;
                       ans.push_back(i*100 + j * 10 + k);
                       mpp[k]++;
                }
                mpp[j]++;
            }
            mpp[i]++;
        }
        return ans;

    }
};
/*
APPROACH
First, we create a frequency array mpp to count how many times each digit (0–9) appears.
Then we loop:
For the hundreds digit from 1 to 9 (it can't be 0 or it wouldn't be a 3-digit number),
For each valid hundreds digit, try all digits (0 to 9) for the tens digit.
For each valid tens digit, try all even digits (0 to 8 step 2) for the units digit.
While building combinations, we make sure that we don’t use a digit more than it appears in the original input.
For each valid (hundreds, tens, units) combination, form the number and add to the result.

*/

