class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n , vector<int>(n));
        int top = 0, bot = n - 1;
        int left = 0, right = n - 1;
        int count = 0;
        while (top <= bot && left <= right) {
            for (int j = left; j <= right; ++j) res[top][j] = ++count;
            ++top;
            for (int i = top; i <= bot; ++i) res[i][right] = ++count;
            --right;
            if (top <= bot) {
                for (int j = right; j >= left; --j) res[bot][j] = ++count;
                --bot;
            }
            if (left <= right) {
                for (int i = bot; i >= top; --i) res[i][left] = ++count;
                ++left;
            }
        }
        return res;
    }
};