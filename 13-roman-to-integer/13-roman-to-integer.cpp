class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mpp;
         mpp['V']= 5;
                mpp['I']= 1; 
                mpp['X']= 10;
                mpp['L']= 50;
                mpp['C']= 100;
                 mpp['D']= 500;
                 mpp['M']= 1000;
        int n=s.size();
        int ans=0;
        int prev=0;
        for(int i=n-1;i>=0;i--){
            if(mpp[s[i]]<prev){
                ans-=mpp[s[i]];
            }else{
                ans+=mpp[s[i]];
            }
            prev=mpp[s[i]];
        }
        return ans;
    }
};