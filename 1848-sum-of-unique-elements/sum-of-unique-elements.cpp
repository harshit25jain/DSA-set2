class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

    //  Step 1 : Use Map Store Freq And Sum Variables.
      map<int,int>Freq;
      int Sum=0;

    //  Step 2 : Store Freq Each Element.
      for(int i:nums){
        Freq[i]++;
      }  

      // Step 2 : Checking A Freq
       for(auto[Key,Count]:Freq){
        if(Count==1) Sum+=Key;   
      }
      
      return Sum;

    }
};