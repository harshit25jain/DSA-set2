class Solution {
public:
    int getDistance(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<int> distances;
        
        for(int i = 0; i < 4; i++) {
            for(int j = i + 1; j < 4; j++) {
                int dist = getDistance(points[i], points[j]);
                if(dist == 0) return false; 
                distances.insert(dist);
            }
        }
        return distances.size() == 2;
    }
};
/*
Store the given 4 points in a vector for easier iteration.
Calculate all pairwise distances between the points using the helper function getDistance.
Use a set to store unique distances. If any distance is 0 (overlapping points), return false.
Check the size of the set. For a valid square, there should be exactly 2 unique distances:
One for the side length (appears 4 times).
One for the diagonal length (appears 2 times).
Return true if the above conditions are met. Otherwise, return false.
*/

