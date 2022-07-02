class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });
        int ans=0;
            for(int i=0;i<boxTypes.size();i++){
                int x=min(truckSize,boxTypes[i][0]);
                ans+=x*boxTypes[i][1];
                truckSize-=x;
            }
        return ans;
    }
};