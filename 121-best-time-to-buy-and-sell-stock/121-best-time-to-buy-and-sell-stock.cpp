class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;
        int op = 0;
        int pist = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf)
                lsf = prices[i];
            
            else if(op < prices[i] - lsf)
                op =  prices[i] - lsf;
            
        }
        return op;
    }
};