class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tank=0;
        int start=0;
        int required=0;
        
        for(int i=0;i<gas.size();i++){
            tank+=gas[i]-cost[i];
            if(tank<0){
                start=i+1;
                required+=tank;
                tank=0;
            }
        }
        if(tank+required>=0)
            return start;
        else
            return -1;
    }
};