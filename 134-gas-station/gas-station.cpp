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
/*
Track Totals: Keep running sums of total gas and total cost to determine if a solution exists
Simulate Journey: Use a fuel variable to track current tank level as we traverse
Reset Strategy: When fuel goes negative at station i, we know:
We cannot reach station i from current start
Any station between current start and i also cannot reach station i
Therefore, set new start = i + 1 and reset fuel = 0
*/
