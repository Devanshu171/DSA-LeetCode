class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxporfit=0;
        int buy=10e5;
        int n=prices.size();
        for(int i=0;i<n;i++){
            buy=min(buy,prices[i]);
            maxporfit=max(maxporfit,prices[i]-buy);
        }
        return maxporfit;
    }
};