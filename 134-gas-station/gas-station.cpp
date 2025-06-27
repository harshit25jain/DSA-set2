class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, fuel = 0, start = 0;
        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            fuel += gas[i] - cost[i];
            if (fuel < 0) {
                start = i+1;
                fuel = 0;
            }
        }
        return (totalGas < totalCost) ? -1 : start;
    }
};