class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int start=0,fuel=0;
        int totalg=0,totalc=0;
        for(int i=0;i<gas.size();i++)
        {
            fuel = fuel + gas[i] - cost[i];
            totalg += gas[i];
            totalc += cost[i];
            if(fuel < 0)
            {
                start=i+1;
                fuel =0;
            }
        }
        return (totalg < totalc) ? -1 : start;
    }
};