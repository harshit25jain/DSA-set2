class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int count = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '-') continue;
            if (count == k) {
                res.push_back('-');
                count = 0;
            }
            res += toupper(s[i]);
            ++count;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};