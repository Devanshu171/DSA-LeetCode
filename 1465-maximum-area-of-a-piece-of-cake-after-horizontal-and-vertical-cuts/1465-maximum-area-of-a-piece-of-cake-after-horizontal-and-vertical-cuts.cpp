class Solution {
public:
    #define mod 1000000007
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n=horizontalCuts.size();
        int m=verticalCuts.size();
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        int l=horizontalCuts[0]%mod,b=verticalCuts[0]%mod;
        for(int i=1;i<n;i++){
           l=max(l,horizontalCuts[i]-horizontalCuts[i-1])%mod;
        }
        l=max(l,h-horizontalCuts[n-1])%mod;
         for(int i=1;i<m;i++){
           b=max(b,verticalCuts[i]-verticalCuts[i-1])%mod;
        }
        b=max(b,w-verticalCuts[m-1])%mod;
        
        return ((l%mod)*1ll*(b%mod))%mod;
    }
};