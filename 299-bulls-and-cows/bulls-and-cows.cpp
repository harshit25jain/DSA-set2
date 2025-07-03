class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]) x++;}

        for(char i:secret){
        auto it = find(guess.begin(), guess.end(), i);
        if (it != guess.end()) {
        guess.erase(it);
        y++;}}
        y=y-x;
        string ans;
        ans+=to_string(x);
        ans.push_back('A');
        ans+=to_string(y);
        ans.push_back('B');
        return ans;
    }
};